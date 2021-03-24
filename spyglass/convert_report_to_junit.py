#!/usr/bin/env python3.6

import argparse
from itertools import groupby, zip_longest
from textwrap import wrap
from xml.dom import minidom
import re
import sys
from xml.dom.minidom import Document

parser = argparse.ArgumentParser(description="Converts Spyglass lint reports of the lint/lint_rtl goal in 'moresimple' format to Junit XML reports. The resuling XML is printed to STDOUT. Pipe it into a file if necessary.")
parser.add_argument("src_report", type=argparse.FileType('r'), help="Spyglass 'moresimple' report location.")
parser.add_argument("--error-level", type=str, choices=['warning', 'error', 'fatal'], default='warning')
parser.add_argument("--fail-on-error", help= "Exit with return code 1 if there are lint errors. Use this for CI jobs to report failing.", action="store_true")

args = parser.parse_args()

report_file = args.src_report

regex = re.compile(r"#+ (?:[\w\-]* -> \w*=)?(?P<rule_type>[\w\-/ ]+)#+ *\n\+* *\n(?P<header>.*)\n=+\n(?P<messages>(?:(?!\+).*\n)*)")
header_regex = re.compile(r"(?P<id>ID *)(?P<rule>Rule *)(?P<alias>Alias *)(?P<severity>Severity *)(?P<file>File *)(?P<line>Line *)(?P<wt>Wt *)(?P<message>Message *)")

FIELDS = ["id", "rule", "alias", "severity", "file", "line", "wt", "message"]
error_levels = {
    'fatal' : ['Fatal'],
    'error' : ['Fatal', 'Error', 'SynthesisError'],
    'warning': ['Fatal', 'Error', 'SynthesisError', 'Warning', 'SynthesisWarning']
}

try:
    messages = []
    for match in re.finditer(regex, report_file.read()):
        # Create a new testsuite for each group of lint messages
        rule_type = match.group("rule_type")
        header = match.group("header")
        header_match = re.match(header_regex, header)
        if not header_match:
            parser.error("Error while parsing report file")

        # Parse fields of individual messages
        for line in match.group("messages").splitlines():
            message = {"rule_type": rule_type}
            for field_name in FIELDS:
                start_pos = header_match.start(field_name)
                end_pos = header_match.end(field_name)
                #  If the end position equals the end position of th whole
                #  header line, consume the field until the end of the message
                #  line
                if end_pos == header_match.end():
                    end_pos = len(line)
                field_value = line[start_pos:end_pos]
                message[field_name] = field_value.strip()
            if message['severity'] in error_levels[args.error_level]:
                messages.append(message)

    doc = Document()
    nr_of_failures = len([message for message in messages if message['severity'] in error_levels[args.error_level]])
    testsuite = doc.createElement("testsuite")
    testsuite.setAttribute("name", "lint_rtl")
    testsuite.setAttribute("failures", str(nr_of_failures))
    testsuite.setAttribute("errors", str(nr_of_failures))

    # Group messages by rule_type
    for rule_type, messages_by_ruletype in groupby(messages, lambda msg: msg['rule_type']):
        for rule, messages_by_rule in groupby(messages_by_ruletype, lambda msg: msg['alias'] if msg['alias'] else msg['rule']):
            testcase = doc.createElement("testcase")
            testcase.setAttribute("name", rule)
            testcase.setAttribute("classname", rule_type)
            failure = doc.createElement("failure")
            # Generate an ASCII table from the collected messages
            header = "{: <10s}   {: <17s}   {: <37s}".format("Severity", "File", "Message").rstrip()
            body = []
            for msg in messages_by_rule:
                severity = msg['severity']
                for severity, file, message in zip_longest(wrap(msg['severity'], 10), wrap(msg['file']+", line "+msg['line'], 17), wrap(msg['message'], 37), fillvalue=""):
                    body.append("{: <10s}   {: <17s}   {: <37s}".format(severity, file, message).rstrip())
                body.append("")

            content_text ="\n".join([header, "-"*70, *body])
            content = doc.createTextNode(content_text)
            failure.appendChild(content)
            testcase.appendChild(failure)
            testsuite.appendChild(testcase)
    doc.appendChild(testsuite)
    print(doc.toprettyxml())
    sys.exit(1 if nr_of_failures and args.fail_on_error else 0)


except Exception as e:
    # parser.error("Failed to parse the report. Error: {}".format(e))
    raise e


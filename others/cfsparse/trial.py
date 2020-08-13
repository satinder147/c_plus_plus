from configparser import ConfigParser
with open('cfg.txt') as f:
    data = f.read()

data = {'person1':{'name':'satinder','age':22},
        'person2':{'name':'karan','age':20}                                    }
cfg = ConfigParser()
cfg.read_dict(data)
print(cfg.sections()) # print the sections
for key in cfg.keys():
    for key2 in cfg[key].keys():
        print(key,cfg[key][key2])
# If we have a dictionary we just use
# cfg.read_dict(data), cfg.read_string(data)

"""
writing 
"""

cfg2 = ConfigParser()
cfg2['default'] = {'a':{'parraot':'green'},'b':2}
cfg2['d'] = {}
# cfg2['facebook']['msg'] = 'hola'
# cfg2['google']['gmail'] = 'email'

with open('cfg2.ini','w') as f:
    cfg2.write(f)
# configuration files can have : in place of =
# All values in key-value pair is stored as
#String

#comments # or ,

"""
Section can be indented but that does not mean
anything special, only to increase readibility


In config parsers, values can span multiple 
lines as long as they are indented more than
the key that holds them. By default parsers 
also let empty lines to be parts of values.
At the same time, keys can be arbitrarily 
indented themselves to improve readability. 
In consequence, when configuration files get
big and complex, it is easy for the user to
lose track of the file structure. 
"""
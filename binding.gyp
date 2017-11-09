{
  'targets': [
    {
      'target_name': 'capturesupport',
      'sources': [
        'src/addon.cc',
        'src/capturesupport.cc',
        'src/plugin/PluginHeaderHelper.cc'
      ],
      "conditions": [
        ['OS=="mac"', {
          'link_settings': {
            'libraries': [
              '-framework CoreMediaIO'
            ]
          },
        }]
      ]
    }
  ]
}

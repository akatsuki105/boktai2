	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r4, r1, #0
	movs r2, #0
	ldr r0, _081E37F0 @ =0x000003E7
	cmp r4, r0
	ble _081E37BC
	ldr r1, _081E37F4 @ =0xFFFFFC18
_081E37B4:
	adds r2, #1
	adds r4, r4, r1
	cmp r4, r0
	bgt _081E37B4
_081E37BC:
	ldr r1, _081E37F8 @ =0x000015E6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #3
	bne _081E3804
	ldr r3, _081E37FC @ =0x00001616
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E3804
	movs r6, #0xa4
	lsls r6, r6, #1
	adds r0, r5, r6
	ldr r7, _081E3800 @ =0x00000AA8
	adds r1, r5, r7
	adds r3, r2, #0
	adds r3, #0xa
	lsls r3, r3, #1
	movs r6, #0xaf
	lsls r6, r6, #4
	adds r2, r5, r6
	adds r2, r2, r3
	ldrh r2, [r2]
	bl MainSprite_LoadPose
	b _081E381E
	.align 2, 0
_081E37F0: .4byte 0x000003E7
_081E37F4: .4byte 0xFFFFFC18
_081E37F8: .4byte 0x000015E6
_081E37FC: .4byte 0x00001616
_081E3800: .4byte 0x00000AA8
_081E3804:
	movs r7, #0xa4
	lsls r7, r7, #1
	adds r0, r5, r7
	ldr r3, _081E3868 @ =0x00000AA8
	adds r1, r5, r3
	lsls r3, r2, #1
	movs r6, #0xaf
	lsls r6, r6, #4
	adds r2, r5, r6
	adds r2, r2, r3
	ldrh r2, [r2]
	bl MainSprite_LoadPose
_081E381E:
	movs r2, #0
	adds r3, r5, #0
	adds r3, #0xe8
	adds r6, r5, #0
	adds r6, #0x88
	movs r7, #0x28
	adds r7, r7, r5
	mov r8, r7
	cmp r4, #0x63
	ble _081E383A
_081E3832:
	adds r2, #1
	subs r4, #0x64
	cmp r4, #0x63
	bgt _081E3832
_081E383A:
	ldr r1, _081E386C @ =0x000015E6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #2
	bne _081E3874
	ldr r7, _081E3870 @ =0x00001616
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E3874
	ldr r0, _081E3868 @ =0x00000AA8
	adds r1, r5, r0
	adds r2, #0xa
	lsls r2, r2, #1
	movs r7, #0xaf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl MainSprite_LoadPose
	b _081E388A
	.align 2, 0
_081E3868: .4byte 0x00000AA8
_081E386C: .4byte 0x000015E6
_081E3870: .4byte 0x00001616
_081E3874:
	ldr r0, _081E38C8 @ =0x00000AA8
	adds r1, r5, r0
	lsls r2, r2, #1
	movs r7, #0xaf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r3, #0
	bl MainSprite_LoadPose
_081E388A:
	movs r2, #0
	cmp r4, #9
	ble _081E3898
_081E3890:
	adds r2, #1
	subs r4, #0xa
	cmp r4, #9
	bgt _081E3890
_081E3898:
	ldr r1, _081E38CC @ =0x000015E6
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _081E38D4
	ldr r3, _081E38D0 @ =0x00001616
	adds r0, r5, r3
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E38D4
	ldr r7, _081E38C8 @ =0x00000AA8
	adds r1, r5, r7
	adds r2, #0xa
	lsls r2, r2, #1
	movs r3, #0xaf
	lsls r3, r3, #4
	adds r0, r5, r3
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r6, #0
	bl MainSprite_LoadPose
	b _081E38EA
	.align 2, 0
_081E38C8: .4byte 0x00000AA8
_081E38CC: .4byte 0x000015E6
_081E38D0: .4byte 0x00001616
_081E38D4:
	ldr r7, _081E3928 @ =0x00000AA8
	adds r1, r5, r7
	lsls r2, r2, #1
	movs r3, #0xaf
	lsls r3, r3, #4
	adds r0, r5, r3
	adds r0, r0, r2
	ldrh r2, [r0]
	adds r0, r6, #0
	bl MainSprite_LoadPose
_081E38EA:
	movs r2, #0
	cmp r4, #0
	ble _081E38F8
_081E38F0:
	adds r2, #1
	subs r4, #1
	cmp r4, #0
	bgt _081E38F0
_081E38F8:
	ldr r6, _081E392C @ =0x000015E6
	adds r0, r5, r6
	ldrb r0, [r0]
	cmp r0, #0
	bne _081E3934
	ldr r7, _081E3930 @ =0x00001616
	adds r0, r5, r7
	ldrb r0, [r0]
	cmp r0, #7
	bne _081E3934
	ldr r0, _081E3928 @ =0x00000AA8
	adds r1, r5, r0
	adds r2, #0xa
	lsls r2, r2, #1
	movs r3, #0xaf
	lsls r3, r3, #4
	adds r0, r5, r3
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, r8
	bl MainSprite_LoadPose
	b _081E394A
	.align 2, 0
_081E3928: .4byte 0x00000AA8
_081E392C: .4byte 0x000015E6
_081E3930: .4byte 0x00001616
_081E3934:
	ldr r6, _081E3954 @ =0x00000AA8
	adds r1, r5, r6
	lsls r2, r2, #1
	movs r7, #0xaf
	lsls r7, r7, #4
	adds r0, r5, r7
	adds r0, r0, r2
	ldrh r2, [r0]
	mov r0, r8
	bl MainSprite_LoadPose
_081E394A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081E3954: .4byte 0x00000AA8

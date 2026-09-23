	.include "asm/macros.inc"

	.syntax unified
	
	.text

	thumb_func_start FUN_081dc6d0
FUN_081dc6d0: @ 0x081DC6D0
	push {r4, r5, r6, lr}
	mov r6, r8
	push {r6}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r4, _081DC768 @ =0x0000C091
	ldr r1, _081DC76C @ =0x0000CD91
	adds r0, r4, #0
	bl GetFile
	ldr r1, _081DC770 @ =0x0000082C
	adds r5, r6, r1
	str r0, [r5]
	ldr r1, _081DC774 @ =0x0000A413
	adds r0, r4, #0
	bl GetFile
	movs r1, #0x83
	lsls r1, r1, #4
	adds r1, r1, r6
	mov r8, r1
	str r0, [r1]
	movs r0, #9
	str r0, [sp, #0xc]
	ldr r2, [r5]
	movs r4, #0
	str r4, [sp]
	movs r5, #1
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #2
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	movs r0, #3
	str r0, [sp, #0xc]
	mov r1, r8
	ldr r2, [r1]
	str r4, [sp]
	str r5, [sp, #4]
	add r0, sp, #0xc
	str r0, [sp, #8]
	movs r0, #0
	movs r1, #0
	movs r3, #0
	bl Video_SetupBGLayout
	str r4, [sp]
	movs r0, #3
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r0, _081DC778 @ =0x000092B3
	ldr r1, _081DC77C @ =0x000026BB
	bl GetFile
	ldr r1, _081DC780 @ =0x00000834
	adds r6, r6, r1
	adds r0, #0x14
	str r0, [r6]
	ldr r1, _081DC784 @ =0x03004250
	movs r2, #0x80
	lsls r2, r2, #1
	bl CpuSet
	add sp, #0x10
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DC768: .4byte 0x0000C091
_081DC76C: .4byte 0x0000CD91
_081DC770: .4byte 0x0000082C
_081DC774: .4byte 0x0000A413
_081DC778: .4byte 0x000092B3
_081DC77C: .4byte 0x000026BB
_081DC780: .4byte 0x00000834
_081DC784: .4byte 0x03004250

	thumb_func_start FUN_081dc788
FUN_081dc788: @ 0x081DC788
	push {r4, r5, r6, lr}
	adds r6, r0, #0
	movs r0, #0xc
	movs r1, #4
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	ldr r2, _081DC808 @ =0x00000844
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0xc
	movs r1, #8
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	ldr r2, _081DC80C @ =0x00000848
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0xc
	movs r1, #0xc
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	ldr r2, _081DC810 @ =0x0000084C
	adds r1, r6, r2
	str r0, [r1]
	movs r0, #0xc
	movs r1, #0x10
	movs r2, #0xa
	movs r3, #2
	bl TextPanel_Create
	movs r2, #0x85
	lsls r2, r2, #4
	adds r1, r6, r2
	str r0, [r1]
	movs r5, #0
_081DC7D8:
	lsls r0, r5, #2
	ldr r1, _081DC808 @ =0x00000844
	adds r4, r6, r1
	adds r4, r4, r0
	ldr r0, [r4]
	ldr r2, _081DC814 @ =0x0000083C
	adds r1, r6, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	adds r1, r5, #0
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Hide
	adds r5, #1
	cmp r5, #3
	ble _081DC7D8
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DC808: .4byte 0x00000844
_081DC80C: .4byte 0x00000848
_081DC810: .4byte 0x0000084C
_081DC814: .4byte 0x0000083C

	thumb_func_start FUN_081dc818
FUN_081dc818: @ 0x081DC818
	push {r4, r5, r6, lr}
	adds r3, r0, #0
	adds r5, r1, #0
	ldr r1, _081DC874 @ =0x000006FC
	adds r0, r3, r1
	adds r0, r0, r5
	ldrb r1, [r0]
	ldr r0, _081DC878 @ =0x03002C68
	ldr r2, [r0]
	cmp r2, #0
	beq _081DC86C
	lsls r0, r1, #3
	adds r0, r0, r1
	lsls r0, r0, #3
	movs r1, #0xd2
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r6, r2, r0
	cmp r6, #0
	beq _081DC86C
	lsls r0, r5, #2
	ldr r2, _081DC87C @ =0x00000844
	adds r4, r3, r2
	adds r4, r4, r0
	ldr r0, [r4]
	subs r2, #8
	adds r1, r3, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	adds r1, r5, #0
	bl TextPanel_SetMessage
	ldr r0, [r4]
	adds r1, r5, #0
	adds r2, r6, #0
	bl FUN_0804a40c
	ldr r0, [r4]
	bl TextPanel_Start
_081DC86C:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DC874: .4byte 0x000006FC
_081DC878: .4byte 0x03002C68
_081DC87C: .4byte 0x00000844

	thumb_func_start FUN_081dc880
FUN_081dc880: @ 0x081DC880
	push {r4, r5, lr}
	ldr r1, _081DC89C @ =0x00000844
	adds r5, r0, r1
	movs r4, #3
_081DC888:
	ldm r5!, {r0}
	bl TextPanel_Hide
	subs r4, #1
	cmp r4, #0
	bge _081DC888
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DC89C: .4byte 0x00000844

	thumb_func_start FUN_081dc8a0
FUN_081dc8a0: @ 0x081DC8A0
	lsls r3, r0, #1
	adds r3, r3, r0
	lsls r3, r3, #4
	ldr r0, _081DC8BC @ =0x03003ED0
	adds r3, r3, r0
	ldr r0, [r3, #0x2c]
	movs r3, #0x1f
	ands r1, r3
	lsls r1, r1, #1
	adds r0, r0, r1
	ands r2, r3
	lsls r2, r2, #6
	adds r0, r0, r2
	bx lr
	.align 2, 0
_081DC8BC: .4byte 0x03003ED0

	thumb_func_start FUN_081dc8c0
FUN_081dc8c0: @ 0x081DC8C0
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	str r0, [sp]
	mov sl, r1
	movs r7, #0
	movs r5, #0
	mov r0, sl
	lsls r0, r0, #2
	str r0, [sp, #8]
	ldr r1, [sp]
	ldr r2, _081DC984 @ =0x000006FC
	adds r0, r1, r2
	add r0, sl
	mov sb, r0
	mov r0, sl
	lsls r0, r0, #5
	mov r8, r0
_081DC8EA:
	ldr r4, _081DC988 @ =0x085AE248
	add r4, r8
	movs r6, #6
_081DC8F0:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #3
	bl FUN_081dc8a0
	adds r3, r0, #0
	lsls r1, r7, #1
	mov r2, sb
	ldrb r0, [r2]
	lsls r0, r0, #4
	adds r1, r1, r0
	ldr r0, _081DC98C @ =0x085AE208
	adds r1, r1, r0
	ldrh r0, [r1]
	movs r2, #0x80
	lsls r2, r2, #6
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r7, #1
	adds r4, #4
	subs r6, #2
	cmp r6, #0
	bge _081DC8F0
	movs r0, #0x10
	add r8, r0
	adds r5, #1
	cmp r5, #1
	ble _081DC8EA
	movs r7, #0
	movs r5, #0
	ldr r0, [sp, #8]
	add r0, sl
	lsls r0, r0, #3
	str r0, [sp, #4]
	ldr r1, [sp]
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r1, r2
	add r0, sl
	mov r8, r0
_081DC942:
	adds r0, r5, #1
	mov sb, r0
	lsls r0, r5, #2
	adds r0, r0, r5
	lsls r0, r0, #2
	ldr r1, [sp, #4]
	adds r0, r0, r1
	ldr r2, _081DC990 @ =0x085AE32C
	adds r4, r0, r2
	movs r6, #8
_081DC956:
	ldrh r1, [r4]
	ldrh r2, [r4, #2]
	movs r0, #3
	bl FUN_081dc8a0
	adds r3, r0, #0
	mov r1, r8
	ldrb r0, [r1]
	cmp r0, #0
	bne _081DC998
	lsls r2, r7, #1
	adds r1, r0, #0
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r0, _081DC994 @ =0x085AE2C8
	adds r2, r2, r0
	ldrh r0, [r2]
	movs r2, #0xc0
	lsls r2, r2, #6
	b _081DC9B0
	.align 2, 0
_081DC984: .4byte 0x000006FC
_081DC988: .4byte 0x085AE248
_081DC98C: .4byte 0x085AE208
_081DC990: .4byte 0x085AE32C
_081DC994: .4byte 0x085AE2C8
_081DC998:
	lsls r2, r7, #1
	mov r0, r8
	ldrb r1, [r0]
	lsls r0, r1, #2
	adds r0, r0, r1
	lsls r0, r0, #2
	adds r2, r2, r0
	ldr r1, _081DC9D8 @ =0x085AE2C8
	adds r2, r2, r1
	ldrh r0, [r2]
	movs r2, #0x80
	lsls r2, r2, #6
_081DC9B0:
	adds r1, r2, #0
	orrs r0, r1
	strh r0, [r3]
	adds r7, #1
	adds r4, #4
	subs r6, #2
	cmp r6, #0
	bge _081DC956
	mov r5, sb
	cmp r5, #1
	ble _081DC942
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DC9D8: .4byte 0x085AE2C8

	thumb_func_start FUN_081dc9dc
FUN_081dc9dc: @ 0x081DC9DC
	push {r4, r5, r6, r7, lr}
	sub sp, #0x10
	adds r6, r0, #0
	ldr r4, _081DCA94 @ =0x0000CB05
	ldr r1, _081DCA98 @ =0x0000DCC1
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	movs r2, #0xd7
	lsls r2, r2, #3
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r0, r6, r3
	bl OpenMainSpriteFile
	ldr r1, _081DCA9C @ =0x0000B343
	adds r0, r4, #0
	bl GetFile
	adds r1, r0, #0
	ldr r2, _081DCAA0 @ =0x000006BC
	adds r0, r6, r2
	str r1, [r0]
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r0, r6, r3
	bl OpenMainSpriteFile
	movs r7, #0
	movs r4, #0
	adds r5, r6, #0
	adds r5, #0x18
_081DCA22:
	lsls r0, r7, #1
	movs r2, #0xd8
	lsls r2, r2, #3
	adds r1, r6, r2
	adds r1, r1, r0
	strh r4, [r1]
	ldrh r2, [r1]
	str r4, [sp]
	str r4, [sp, #4]
	str r4, [sp, #8]
	str r4, [sp, #0xc]
	adds r0, r5, #0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	movs r3, #0x10
	bl MainSprite_Add
	adds r2, r0, #0
	cmp r2, #0
	bne _081DCA8C
	adds r5, #0x60
	adds r7, #1
	cmp r7, #0xf
	ble _081DCA22
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r1, r6, r0
	movs r0, #4
	strh r0, [r1]
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r3, #0xd3
	lsls r3, r3, #3
	adds r1, r6, r3
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	str r2, [sp, #0xc]
	movs r2, #4
	movs r3, #0x10
	bl MainSprite_Add
	cmp r0, #0
	bne _081DCA8C
	movs r1, #0xc4
	lsls r1, r1, #3
	adds r0, r6, r1
	ldr r1, [r0]
	movs r2, #1
	orrs r1, r2
	str r1, [r0]
_081DCA8C:
	add sp, #0x10
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCA94: .4byte 0x0000CB05
_081DCA98: .4byte 0x0000DCC1
_081DCA9C: .4byte 0x0000B343
_081DCAA0: .4byte 0x000006BC

	thumb_func_start FUN_081dcaa4
FUN_081dcaa4: @ 0x081DCAA4
	push {r4, r5, r6, r7, lr}
	adds r7, r0, #0
	movs r0, #0x97
	lsls r0, r0, #3
	adds r4, r7, r0
	movs r1, #0xc0
	lsls r1, r1, #2
	adds r3, r7, r1
	movs r0, #0xc0
	lsls r0, r0, #1
	adds r2, r7, r0
	movs r5, #0xd8
	adds r1, r7, #0
	movs r6, #3
_081DCAC0:
	strh r5, [r1, #0x38]
	strh r5, [r2, #0x38]
	strh r5, [r3, #0x38]
	strh r5, [r4]
	movs r0, #0x20
	strh r0, [r1, #0x3a]
	movs r0, #0x40
	strh r0, [r2, #0x3a]
	movs r0, #0x60
	strh r0, [r3, #0x3a]
	movs r0, #0x80
	strh r0, [r4, #2]
	adds r4, #0x60
	adds r3, #0x60
	adds r2, #0x60
	subs r5, #8
	adds r1, #0x60
	subs r6, #1
	cmp r6, #0
	bge _081DCAC0
	ldr r1, _081DCB44 @ =0x00000859
	adds r0, r7, r1
	movs r6, #0
	ldrsb r6, [r0, r6]
	cmp r6, #3
	bgt _081DCB2C
	movs r3, #1
	lsls r0, r6, #1
	adds r0, r0, r6
	lsls r0, r0, #7
	adds r1, r0, #0
	adds r1, #0xe0
	adds r1, r1, r7
	adds r0, #0x20
	adds r2, r0, r7
	movs r4, #0xc0
	lsls r4, r4, #1
_081DCB0A:
	ldr r0, [r2]
	orrs r0, r3
	str r0, [r2]
	ldr r0, [r2, #0x60]
	orrs r0, r3
	str r0, [r2, #0x60]
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	ldr r0, [r1, #0x60]
	orrs r0, r3
	str r0, [r1, #0x60]
	adds r1, r1, r4
	adds r2, r2, r4
	adds r6, #1
	cmp r6, #3
	ble _081DCB0A
_081DCB2C:
	movs r0, #0xc7
	lsls r0, r0, #3
	adds r1, r7, r0
	ldr r0, _081DCB48 @ =0x0000FFF8
	strh r0, [r1]
	ldr r0, _081DCB4C @ =0x0000063A
	adds r1, r7, r0
	ldr r0, _081DCB50 @ =0x0000FFC8
	strh r0, [r1]
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCB44: .4byte 0x00000859
_081DCB48: .4byte 0x0000FFF8
_081DCB4C: .4byte 0x0000063A
_081DCB50: .4byte 0x0000FFC8

	thumb_func_start FUN_081dcb54
FUN_081dcb54: @ 0x081DCB54
	push {lr}
	movs r3, #1
	adds r1, r0, #0
	adds r1, #0x20
	movs r2, #0x10
_081DCB5E:
	ldr r0, [r1]
	orrs r0, r3
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _081DCB5E
	pop {r0}
	bx r0

	thumb_func_start FUN_081dcb70
FUN_081dcb70: @ 0x081DCB70
	push {r4, r5, lr}
	adds r4, r0, #0
	adds r4, #0x18
	movs r5, #0x10
_081DCB78:
	adds r0, r4, #0
	bl MainSprite_Remove
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _081DCB78
	pop {r4, r5}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dcb8c
FUN_081dcb8c: @ 0x081DCB8C
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	lsls r2, r1, #1
	ldr r3, _081DCC3C @ =0x000006E4
	adds r0, r6, r3
	adds r0, r0, r2
	ldrh r5, [r0]
	lsls r7, r1, #2
	movs r2, #0
	ldr r0, _081DCC40 @ =0x000003E7
	cmp r5, r0
	ble _081DCBAE
	ldr r1, _081DCC44 @ =0xFFFFFC18
_081DCBA6:
	adds r2, #1
	adds r5, r5, r1
	cmp r5, r0
	bgt _081DCBA6
_081DCBAE:
	lsls r4, r7, #1
	adds r0, r4, r7
	lsls r0, r0, #5
	movs r1, #0x9c
	lsls r1, r1, #1
	adds r0, r0, r1
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #0x63
	ble _081DCBD8
_081DCBD0:
	adds r2, #1
	subs r5, #0x64
	cmp r5, #0x63
	bgt _081DCBD0
_081DCBD8:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0xd8
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #9
	ble _081DCBFC
_081DCBF4:
	adds r2, #1
	subs r5, #0xa
	cmp r5, #9
	bgt _081DCBF4
_081DCBFC:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x78
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	movs r2, #0
	cmp r5, #0
	ble _081DCC20
_081DCC18:
	adds r2, #1
	subs r5, #1
	cmp r5, #0
	bgt _081DCC18
_081DCC20:
	adds r0, r4, r7
	lsls r0, r0, #5
	adds r0, #0x18
	adds r0, r6, r0
	movs r3, #0xcf
	lsls r3, r3, #3
	adds r1, r6, r3
	lsls r2, r2, #0x10
	lsrs r2, r2, #0x10
	bl MainSprite_LoadPose
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCC3C: .4byte 0x000006E4
_081DCC40: .4byte 0x000003E7
_081DCC44: .4byte 0xFFFFFC18

	thumb_func_start FUN_081dcc48
FUN_081dcc48: @ 0x081DCC48
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	mov ip, r0
	mov r8, r1
	ldr r0, _081DCCD4 @ =0x00000856
	add r0, ip
	ldrh r0, [r0]
	adds r1, r0, #0
	muls r1, r0, r1
	adds r0, r1, #0
	asrs r7, r0, #2
	ldr r4, _081DCCD8 @ =0x030046B4
	ldr r1, [r4]
	adds r1, #1
	ldr r5, _081DCCDC @ =0x000003FF
	ands r1, r5
	str r1, [r4]
	ldr r6, _081DCCE0 @ =0x085B0200
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r2, [r0]
	movs r3, #7
	ands r2, r3
	lsls r0, r2, #2
	adds r0, r0, r2
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r0, r1, #1
	adds r0, r0, r6
	ldrh r0, [r0]
	ands r0, r3
	movs r2, #0x64
	muls r0, r2, r0
	adds r7, r7, r0
	adds r1, #1
	ands r1, r5
	str r1, [r4]
	lsls r1, r1, #1
	adds r1, r1, r6
	ldrh r1, [r1]
	ands r1, r3
	lsls r0, r1, #5
	subs r0, r0, r1
	lsls r0, r0, #2
	adds r0, r0, r1
	lsls r0, r0, #3
	adds r7, r7, r0
	ldr r0, _081DCCE4 @ =0x0000270F
	cmp r7, r0
	ble _081DCCB6
	adds r7, r0, #0
_081DCCB6:
	mov r0, r8
	lsls r1, r0, #1
	ldr r0, _081DCCE8 @ =0x000006E4
	add r0, ip
	adds r0, r0, r1
	strh r7, [r0]
	mov r0, ip
	mov r1, r8
	bl FUN_081dcb8c
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCCD4: .4byte 0x00000856
_081DCCD8: .4byte 0x030046B4
_081DCCDC: .4byte 0x000003FF
_081DCCE0: .4byte 0x085B0200
_081DCCE4: .4byte 0x0000270F
_081DCCE8: .4byte 0x000006E4

	thumb_func_start FUN_081dccec
FUN_081dccec: @ 0x081DCCEC
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r1, _081DCD10 @ =0x00000856
	adds r0, r5, r1
	ldrh r0, [r0]
	movs r1, #2
	bl Mod
	cmp r0, #0
	bne _081DCD06
	ldr r0, _081DCD14 @ =0x000002A5
	bl PlaySound_082406e0
_081DCD06:
	movs r4, #0
	ldr r2, _081DCD18 @ =0x00000859
	adds r0, r5, r2
	b _081DCD38
	.align 2, 0
_081DCD10: .4byte 0x00000856
_081DCD14: .4byte 0x000002A5
_081DCD18: .4byte 0x00000859
_081DCD1C:
	lsls r0, r4, #1
	ldr r2, _081DCD48 @ =0x000006EC
	adds r1, r5, r2
	adds r1, r1, r0
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DCD32
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081dcc48
_081DCD32:
	adds r4, #1
	ldr r1, _081DCD4C @ =0x00000859
	adds r0, r5, r1
_081DCD38:
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r4, r0
	blt _081DCD1C
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DCD48: .4byte 0x000006EC
_081DCD4C: .4byte 0x00000859

	thumb_func_start FUN_081dcd50
FUN_081dcd50: @ 0x081DCD50
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DCDAC @ =0x00000834
	adds r4, r5, r0
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe5
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r0, [r4]
	adds r0, #0x40
	movs r2, #0xe9
	lsls r2, r2, #3
	adds r1, r5, r2
	movs r2, #0x10
	bl CpuSet
	ldr r1, _081DCDB0 @ =0x00000704
	adds r0, r5, r1
	movs r1, #0
	strh r1, [r0]
	ldr r2, _081DCDB4 @ =0x00000828
	adds r0, r5, r2
	strh r1, [r0]
	adds r2, #2
	adds r0, r5, r2
	strh r1, [r0]
	ldr r0, _081DCDB8 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DCDBC
	movs r0, #1
	rsbs r0, r0, #0
	b _081DCDC0
	.align 2, 0
_081DCDAC: .4byte 0x00000834
_081DCDB0: .4byte 0x00000704
_081DCDB4: .4byte 0x00000828
_081DCDB8: .4byte 0x03002C68
_081DCDBC:
	movs r1, #0x18
	ldrsh r0, [r0, r1]
_081DCDC0:
	cmp r0, #1
	beq _081DCDD2
	cmp r0, #1
	ble _081DCDEC
	cmp r0, #2
	beq _081DCDDC
	cmp r0, #3
	beq _081DCDE2
	b _081DCDEC
_081DCDD2:
	ldr r0, _081DCDD8 @ =0x0000075C
	adds r1, r5, r0
	b _081DCDF2
	.align 2, 0
_081DCDD8: .4byte 0x0000075C
_081DCDDC:
	movs r2, #0xec
	lsls r2, r2, #3
	b _081DCDF0
_081DCDE2:
	ldr r0, _081DCDE8 @ =0x00000764
	adds r1, r5, r0
	b _081DCDF2
	.align 2, 0
_081DCDE8: .4byte 0x00000764
_081DCDEC:
	movs r2, #0xeb
	lsls r2, r2, #3
_081DCDF0:
	adds r1, r5, r2
_081DCDF2:
	ldr r0, _081DCE0C @ =0x00007FFF
	strh r0, [r1]
	movs r1, #0xe1
	lsls r1, r1, #3
	adds r0, r5, r1
	ldr r1, _081DCE10 @ =0x03004290
	movs r2, #0x10
	bl CpuSet
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DCE0C: .4byte 0x00007FFF
_081DCE10: .4byte 0x03004290

	thumb_func_start FUN_081dce14
FUN_081dce14: @ 0x081DCE14
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	adds r7, r0, #0
	mov sl, r1
	movs r0, #0
	mov sb, r0
	movs r1, #0xf
	str r1, [sp]
_081DCE2C:
	ldr r2, _081DCE40 @ =0x00000828
	adds r0, r7, r2
	ldrh r0, [r0]
	cmp r0, #0
	beq _081DCE44
	movs r3, #0xe5
	lsls r3, r3, #3
	adds r0, r7, r3
	b _081DCE4A
	.align 2, 0
_081DCE40: .4byte 0x00000828
_081DCE44:
	movs r5, #0xe9
	lsls r5, r5, #3
	adds r0, r7, r5
_081DCE4A:
	add r0, sb
	ldrh r1, [r0]
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r0, r7, r2
	add r0, sb
	ldrh r4, [r0]
	movs r3, #0xf9
	lsls r3, r3, #3
	adds r2, r7, r3
	add r2, sb
	adds r0, r1, #0
	movs r5, #0x1f
	ands r0, r5
	mov r8, r4
	mov r3, r8
	ands r3, r5
	mov r8, r3
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r2]
	movs r5, #0xfd
	lsls r5, r5, #3
	adds r6, r7, r5
	add r6, sb
	asrs r0, r1, #5
	movs r3, #0x1f
	ands r0, r3
	asrs r3, r4, #5
	movs r5, #0x1f
	ands r3, r5
	subs r0, r0, r3
	lsls r0, r0, #5
	strh r0, [r6]
	ldr r0, _081DCF28 @ =0x00000808
	adds r5, r7, r0
	add r5, sb
	asrs r0, r1, #0xa
	movs r1, #0x1f
	ands r0, r1
	asrs r4, r4, #0xa
	ands r4, r1
	subs r0, r0, r4
	lsls r0, r0, #5
	strh r0, [r5]
	movs r1, #0
	ldrsh r0, [r2, r1]
	mov r1, sl
	str r2, [sp, #4]
	str r3, [sp, #8]
	bl Div
	ldr r2, [sp, #4]
	strh r0, [r2]
	movs r2, #0
	ldrsh r0, [r6, r2]
	mov r1, sl
	bl Div
	strh r0, [r6]
	movs r1, #0
	ldrsh r0, [r5, r1]
	mov r1, sl
	bl Div
	strh r0, [r5]
	movs r2, #0xed
	lsls r2, r2, #3
	adds r0, r7, r2
	add r0, sb
	mov r5, r8
	lsls r5, r5, #5
	strh r5, [r0]
	movs r1, #0xf1
	lsls r1, r1, #3
	adds r0, r7, r1
	add r0, sb
	ldr r3, [sp, #8]
	lsls r3, r3, #5
	strh r3, [r0]
	adds r2, #0x40
	adds r0, r7, r2
	add r0, sb
	lsls r4, r4, #5
	strh r4, [r0]
	movs r3, #2
	add sb, r3
	ldr r5, [sp]
	subs r5, #1
	str r5, [sp]
	cmp r5, #0
	bge _081DCE2C
	ldr r0, _081DCF2C @ =0x00000828
	adds r2, r7, r0
	ldrh r0, [r2]
	movs r1, #1
	eors r0, r1
	strh r0, [r2]
	ldr r1, _081DCF30 @ =0x00000706
	adds r0, r7, r1
	mov r2, sl
	strh r2, [r0]
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DCF28: .4byte 0x00000808
_081DCF2C: .4byte 0x00000828
_081DCF30: .4byte 0x00000706

	thumb_func_start FUN_081dcf34
FUN_081dcf34: @ 0x081DCF34
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	ldr r0, _081DCF68 @ =0x0000082A
	adds r4, r7, r0
	ldrh r0, [r4]
	cmp r0, #0
	beq _081DCF6C
	subs r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081DCF5A
	b _081DD060
_081DCF5A:
	adds r0, r7, #0
	movs r1, #0x20
	bl FUN_081dce14
	strh r5, [r4]
	b _081DD060
	.align 2, 0
_081DCF68: .4byte 0x0000082A
_081DCF6C:
	ldr r1, _081DCFB4 @ =0x03004290
	mov sl, r1
	movs r2, #0xf1
	lsls r2, r2, #3
	adds r3, r7, r2
	movs r0, #0xed
	lsls r0, r0, #3
	adds r5, r7, r0
	movs r1, #0
	mov r8, r1
	movs r2, #0xf
	mov sb, r2
	adds r0, #0x60
	adds r6, r7, r0
_081DCF88:
	ldrh r0, [r6]
	ldrh r1, [r5]
	adds r0, r0, r1
	strh r0, [r5]
	ldrh r0, [r6, #0x20]
	ldrh r2, [r3]
	adds r0, r0, r2
	strh r0, [r3]
	ldr r1, _081DCFB8 @ =0x00000808
	adds r0, r7, r1
	add r0, r8
	ldrh r0, [r0]
	ldrh r2, [r3, #0x20]
	adds r0, r0, r2
	strh r0, [r3, #0x20]
	movs r1, #0
	ldrsh r0, [r5, r1]
	cmp r0, #0
	blt _081DCFBC
	asrs r0, r0, #5
	b _081DCFC2
	.align 2, 0
_081DCFB4: .4byte 0x03004290
_081DCFB8: .4byte 0x00000808
_081DCFBC:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFC2:
	mov ip, r0
	movs r2, #0
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _081DCFD0
	asrs r0, r0, #5
	b _081DCFD6
_081DCFD0:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFD6:
	adds r1, r0, #0
	movs r2, #0x20
	ldrsh r0, [r3, r2]
	cmp r0, #0
	blt _081DCFE4
	asrs r0, r0, #5
	b _081DCFEA
_081DCFE4:
	rsbs r0, r0, #0
	asrs r0, r0, #5
	rsbs r0, r0, #0
_081DCFEA:
	movs r2, #0xe1
	lsls r2, r2, #3
	adds r4, r7, r2
	mov r2, r8
	adds r2, r4, r2
	str r2, [sp]
	lsls r1, r1, #5
	mov r2, ip
	orrs r1, r2
	lsls r0, r0, #0xa
	orrs r0, r1
	ldr r1, [sp]
	strh r0, [r1]
	adds r3, #2
	adds r5, #2
	adds r6, #2
	movs r2, #2
	add r8, r2
	movs r0, #1
	rsbs r0, r0, #0
	add sb, r0
	mov r1, sb
	cmp r1, #0
	bge _081DCF88
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0x10
	bl CpuSet
	ldr r2, _081DD048 @ =0x00000706
	adds r1, r7, r2
	ldrh r0, [r1]
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081DD060
	ldr r1, _081DD04C @ =0x00000828
	adds r0, r7, r1
	ldrh r0, [r0]
	cmp r0, #0
	bne _081DD054
	ldr r2, _081DD050 @ =0x0000082A
	adds r1, r7, r2
	movs r0, #0x14
	strh r0, [r1]
	b _081DD05C
	.align 2, 0
_081DD048: .4byte 0x00000706
_081DD04C: .4byte 0x00000828
_081DD050: .4byte 0x0000082A
_081DD054:
	adds r0, r7, #0
	movs r1, #0x20
	bl FUN_081dce14
_081DD05C:
	movs r0, #1
	b _081DD062
_081DD060:
	movs r0, #0
_081DD062:
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start FUN_081dd074
FUN_081dd074: @ 0x081DD074
	push {r4, r5, r6, lr}
	sub sp, #0x20
	mov r6, sp
	lsls r4, r1, #1
	ldr r3, _081DD0B0 @ =0x000006F4
	adds r5, r0, r3
	adds r4, r5, r4
	ldrh r3, [r4]
	strh r3, [r6, #0x10]
	mov r3, sp
	ldr r6, _081DD0B4 @ =0x000006FC
	adds r0, r0, r6
	adds r1, r0, r1
	ldrb r6, [r1]
	strb r6, [r3, #0x18]
	lsls r3, r2, #1
	adds r5, r5, r3
	ldrh r3, [r5]
	strh r3, [r4]
	adds r0, r0, r2
	ldrb r2, [r0]
	strb r2, [r1]
	mov r1, sp
	ldrh r1, [r1, #0x10]
	strh r1, [r5]
	strb r6, [r0]
	add sp, #0x20
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_081DD0B0: .4byte 0x000006F4
_081DD0B4: .4byte 0x000006FC

	thumb_func_start FUN_081dd0b8
FUN_081dd0b8: @ 0x081DD0B8
	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	movs r1, #0
	b _081DD106
_081DD0C0:
	movs r2, #0
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	adds r7, r1, #1
	cmp r2, r0
	bge _081DD104
	ldr r0, _081DD11C @ =0x000006F4
	adds r5, r6, r0
_081DD0D6:
	lsls r0, r2, #1
	adds r0, r5, r0
	adds r4, r2, #1
	lsls r1, r4, #1
	adds r1, r5, r1
	ldrh r0, [r0]
	ldrh r1, [r1]
	cmp r0, r1
	bhs _081DD0F2
	adds r0, r6, #0
	adds r1, r2, #0
	adds r2, r4, #0
	bl FUN_081dd074
_081DD0F2:
	adds r2, r4, #0
	ldr r1, _081DD120 @ =0x00000859
	adds r0, r6, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	subs r0, #1
	cmp r2, r0
	blt _081DD0D6
_081DD104:
	adds r1, r7, #0
_081DD106:
	ldr r3, _081DD120 @ =0x00000859
	adds r0, r6, r3
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _081DD0C0
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD11C: .4byte 0x000006F4
_081DD120: .4byte 0x00000859

	thumb_func_start FUN_081dd124
FUN_081dd124: @ 0x081DD124
	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r6, r0, #0
	movs r4, #0
	movs r7, #1
	movs r3, #0
	ldr r0, _081DD188 @ =0x00000859
	adds r1, r6, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	subs r0, #1
	cmp r4, r0
	bge _081DD1A8
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r2, r2, r6
	mov sb, r2
	ldr r0, _081DD18C @ =0x000006EC
	adds r0, r0, r6
	mov r8, r0
	ldr r2, _081DD190 @ =0x000006F4
	adds r5, r6, r2
	ldr r0, _081DD194 @ =0x085AE3CC
	mov sl, r0
	mov ip, r1
_081DD15C:
	mov r1, sb
	adds r0, r1, r3
	strb r4, [r0]
	lsls r1, r3, #1
	mov r0, r8
	adds r2, r0, r1
	lsls r0, r4, #1
	add r0, sl
	ldrh r0, [r0]
	strh r0, [r2]
	adds r1, r5, r1
	adds r2, r3, #1
	lsls r0, r2, #1
	adds r0, r5, r0
	ldrh r1, [r1]
	ldrh r0, [r0]
	cmp r1, r0
	beq _081DD198
	adds r4, r4, r7
	movs r7, #1
	b _081DD19A
	.align 2, 0
_081DD188: .4byte 0x00000859
_081DD18C: .4byte 0x000006EC
_081DD190: .4byte 0x000006F4
_081DD194: .4byte 0x085AE3CC
_081DD198:
	adds r7, #1
_081DD19A:
	adds r3, r2, #0
	mov r1, ip
	movs r0, #0
	ldrsb r0, [r1, r0]
	subs r0, #1
	cmp r3, r0
	blt _081DD15C
_081DD1A8:
	movs r2, #0xe0
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r0, r0, r3
	strb r4, [r0]
	lsls r0, r3, #1
	subs r2, #0x14
	adds r1, r6, r2
	adds r1, r1, r0
	lsls r0, r4, #1
	ldr r2, _081DD1D4 @ =0x085AE3CC
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD1D4: .4byte 0x085AE3CC

	thumb_func_start FUN_081dd1d8
FUN_081dd1d8: @ 0x081DD1D8
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r5, #0
	b _081DD232
_081DD1E0:
	lsls r2, r5, #1
	ldr r3, _081DD248 @ =0x000006EC
	adds r0, r4, r3
	adds r1, r0, r2
	ldrh r0, [r1]
	cmp r0, #0
	beq _081DD230
	subs r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081DD230
	ldr r0, _081DD24C @ =0x000006E4
	adds r1, r4, r0
	adds r1, r1, r2
	adds r3, #8
	adds r0, r4, r3
	adds r0, r0, r2
	ldrh r0, [r0]
	strh r0, [r1]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_081dcb8c
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_081dc8c0
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_081dc818
	ldr r0, _081DD250 @ =0x00000167
	bl PlaySound_082406e0
	ldr r0, _081DD254 @ =0x00000858
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	strb r0, [r1]
_081DD230:
	adds r5, #1
_081DD232:
	ldr r1, _081DD258 @ =0x00000859
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r5, r0
	blt _081DD1E0
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD248: .4byte 0x000006EC
_081DD24C: .4byte 0x000006E4
_081DD250: .4byte 0x00000167
_081DD254: .4byte 0x00000858
_081DD258: .4byte 0x00000859

	thumb_func_start FUN_081dd25c
FUN_081dd25c: @ 0x081DD25C
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DD270 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DD274
	movs r4, #1
	rsbs r4, r4, #0
	b _081DD278
	.align 2, 0
_081DD270: .4byte 0x03002C68
_081DD274:
	movs r1, #0x18
	ldrsh r4, [r0, r1]
_081DD278:
	movs r2, #0
	ldr r0, _081DD2B4 @ =0x00000859
	adds r1, r5, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bge _081DD2D4
	adds r3, r1, #0
	ldr r0, _081DD2B8 @ =0x000006FC
	adds r1, r5, r0
	ldr r5, _081DD2BC @ =0x030046A0
_081DD28E:
	ldrb r0, [r1]
	cmp r0, r4
	bne _081DD2C8
	ldrb r0, [r1, #4]
	cmp r0, #0
	bne _081DD2D4
	ldr r0, [r5]
	ldr r2, _081DD2C0 @ =0x00000916
	adds r1, r0, r2
	movs r2, #0
	ldrsh r0, [r1, r2]
	adds r0, #1
	ldr r2, _081DD2C4 @ =0x0000270F
	cmp r0, r2
	ble _081DD2AE
	adds r0, r2, #0
_081DD2AE:
	strh r0, [r1]
	b _081DD2D4
	.align 2, 0
_081DD2B4: .4byte 0x00000859
_081DD2B8: .4byte 0x000006FC
_081DD2BC: .4byte 0x030046A0
_081DD2C0: .4byte 0x00000916
_081DD2C4: .4byte 0x0000270F
_081DD2C8:
	adds r1, #1
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r2, r0
	blt _081DD28E
_081DD2D4:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start FUN_081dd2dc
FUN_081dd2dc: @ 0x081DD2DC
	push {r4, r5, r6, r7, lr}
	adds r4, r0, #0
	movs r3, #0
	ldr r0, _081DD308 @ =0x00000859
	adds r1, r4, r0
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r3, r0
	bge _081DD328
	ldr r0, _081DD30C @ =0x03002C68
	ldr r5, [r0]
	adds r6, r1, #0
	ldr r7, _081DD310 @ =0x000006F4
	adds r2, r4, r7
	movs r0, #0x98
	lsls r0, r0, #1
	adds r1, r5, r0
_081DD2FE:
	cmp r5, #0
	bne _081DD314
	movs r0, #0
	b _081DD318
	.align 2, 0
_081DD308: .4byte 0x00000859
_081DD30C: .4byte 0x03002C68
_081DD310: .4byte 0x000006F4
_081DD314:
	movs r7, #0
	ldrsh r0, [r1, r7]
_081DD318:
	strh r0, [r2]
	adds r2, #2
	adds r1, #2
	adds r3, #1
	movs r0, #0
	ldrsb r0, [r6, r0]
	cmp r3, r0
	blt _081DD2FE
_081DD328:
	ldr r0, _081DD360 @ =0x000006FC
	adds r1, r4, r0
	movs r0, #0
	strb r0, [r1]
	ldr r7, _081DD364 @ =0x000006FD
	adds r1, r4, r7
	movs r0, #1
	strb r0, [r1]
	ldr r0, _081DD368 @ =0x000006FE
	adds r1, r4, r0
	movs r0, #2
	strb r0, [r1]
	adds r7, #2
	adds r1, r4, r7
	movs r0, #3
	strb r0, [r1]
	adds r0, r4, #0
	bl FUN_081dd0b8
	adds r0, r4, #0
	bl FUN_081dd124
	adds r0, r4, #0
	bl FUN_081dd25c
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_081DD360: .4byte 0x000006FC
_081DD364: .4byte 0x000006FD
_081DD368: .4byte 0x000006FE

	thumb_func_start FUN_081dd36c
FUN_081dd36c: @ 0x081DD36C
	push {r4, lr}
	adds r1, r0, #0
	ldr r0, _081DD37C @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _081DD388
	b _081DD3BA
	.align 2, 0
_081DD37C: .4byte 0x03002C68
_081DD380:
	movs r0, #0xa9
	bl sound_08240264
	b _081DD3BA
_081DD388:
	movs r2, #0x18
	ldrsh r3, [r0, r2]
	cmp r3, #0
	blt _081DD3BA
	movs r2, #0
	ldr r4, _081DD3C0 @ =0x00000859
	adds r0, r1, r4
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r2, r0
	bge _081DD3BA
	adds r4, r0, #0
	ldr r0, _081DD3C4 @ =0x000006FC
	adds r1, r1, r0
_081DD3A6:
	ldrb r0, [r1]
	cmp r0, r3
	bne _081DD3B2
	ldrb r0, [r1, #4]
	cmp r0, #0
	beq _081DD380
_081DD3B2:
	adds r1, #1
	adds r2, #1
	cmp r2, r4
	blt _081DD3A6
_081DD3BA:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081DD3C0: .4byte 0x00000859
_081DD3C4: .4byte 0x000006FC

	thumb_func_start FUN_081dd3c8
FUN_081dd3c8: @ 0x081DD3C8
	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _081DD428 @ =0x00000855
	adds r4, r5, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DD3E8
	movs r0, #1
	bl FUN_081df8f0
	ldr r1, _081DD42C @ =0x00000856
	adds r0, r5, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r4]
_081DD3E8:
	ldr r0, _081DD42C @ =0x00000856
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r1, r0, #0
	cmp r1, #9
	bls _081DD406
	cmp r1, #0xa
	bne _081DD40A
	ldr r1, _081DD430 @ =0x00000844
	adds r0, r5, r1
	ldr r0, [r0]
	movs r1, #5
	bl TextPanel_SetMessage
	ldrh r0, [r4]
_081DD406:
	adds r0, #1
	strh r0, [r4]
_081DD40A:
	bl FUN_081dfa04
	cmp r0, #0x11
	beq _081DD416
	cmp r0, #0x14
	bne _081DD422
_081DD416:
	adds r0, r5, #0
	bl FUN_081dcb54
	adds r0, r5, #0
	bl KillEntity
_081DD422:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD428: .4byte 0x00000855
_081DD42C: .4byte 0x00000856
_081DD430: .4byte 0x00000844

	thumb_func_start FUN_081dd434
FUN_081dd434: @ 0x081DD434
	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r6, r0, #0
	ldr r0, _081DD518 @ =0x00000855
	adds r7, r6, r0
	ldrb r0, [r7]
	cmp r0, #0
	beq _081DD4E0
	adds r0, r6, #0
	bl FUN_081dc880
	adds r0, r6, #0
	bl FUN_081dcb54
	movs r0, #0
	bl ClearBGTilemapBuffer
	movs r0, #1
	bl ClearBGTilemapBuffer
	movs r0, #2
	bl ClearBGTilemapBuffer
	movs r0, #3
	bl ClearBGTilemapBuffer
	movs r5, #0
	str r5, [sp]
	movs r0, #0
	movs r1, #0
	movs r2, #0
	movs r3, #0
	bl Video_GenerateBGMap
	ldr r1, _081DD51C @ =0x00000844
	adds r4, r6, r1
	ldr r0, [r4]
	movs r1, #6
	str r1, [sp]
	movs r1, #1
	movs r2, #7
	movs r3, #0x1c
	bl TextPanel_SetRect
	ldr r0, [r4]
	ldr r2, _081DD520 @ =0x0000083C
	adds r1, r6, r2
	ldr r1, [r1]
	bl TextPanel_SetScript
	ldr r0, [r4]
	movs r1, #4
	bl TextPanel_SetMessage
	ldr r0, [r4]
	bl TextPanel_Start
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r2, r6, r3
	ldr r0, [r2]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	str r0, [r2]
	ldr r0, _081DD524 @ =0x0000085A
	adds r1, r6, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD528 @ =0x00000856
	adds r0, r6, r1
	movs r1, #0
	strh r5, [r0]
	strb r1, [r7]
	movs r2, #0xc3
	lsls r2, r2, #3
	adds r0, r6, r2
	adds r3, #0x78
	adds r1, r6, r3
	adds r3, #0x48
	adds r2, r6, r3
	ldrh r2, [r2]
	str r5, [sp]
	movs r3, #1
	bl MainSprite_SetAnim
_081DD4E0:
	ldr r0, _081DD52C @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #0x20
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r5, r0, #0x10
	cmp r5, #0
	beq _081DD530
	ldr r0, _081DD524 @ =0x0000085A
	adds r1, r6, r0
	ldrb r5, [r1]
	cmp r5, #0
	beq _081DD4FC
	b _081DD610
_081DD4FC:
	movs r2, #0xdc
	lsls r2, r2, #3
	adds r4, r6, r2
	movs r0, #4
	strh r0, [r4]
	movs r0, #1
	strb r0, [r1]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r3, #0xc3
	lsls r3, r3, #3
	adds r0, r6, r3
	b _081DD55C
	.align 2, 0
_081DD518: .4byte 0x00000855
_081DD51C: .4byte 0x00000844
_081DD520: .4byte 0x0000083C
_081DD524: .4byte 0x0000085A
_081DD528: .4byte 0x00000856
_081DD52C: .4byte 0x030044E0
_081DD530:
	movs r0, #0x10
	ands r0, r1
	cmp r0, #0
	beq _081DD574
	ldr r3, _081DD570 @ =0x0000085A
	adds r2, r6, r3
	ldrb r0, [r2]
	cmp r0, #0
	beq _081DD610
	movs r0, #0xdc
	lsls r0, r0, #3
	adds r4, r6, r0
	movs r1, #0
	movs r0, #5
	strh r0, [r4]
	strb r1, [r2]
	movs r0, #0xdc
	bl PlaySound_082406e0
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
_081DD55C:
	movs r2, #0xd3
	lsls r2, r2, #3
	adds r1, r6, r2
	ldrh r2, [r4]
	str r5, [sp]
	movs r3, #1
	bl MainSprite_SetAnim
	b _081DD610
	.align 2, 0
_081DD570: .4byte 0x0000085A
_081DD574:
	movs r5, #1
	movs r2, #1
	adds r0, r2, #0
	ands r0, r1
	cmp r0, #0
	beq _081DD5CC
	movs r3, #0xc4
	lsls r3, r3, #3
	adds r1, r6, r3
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	ldr r0, _081DD5BC @ =0x0000085A
	adds r4, r6, r0
	ldrb r0, [r4]
	bl FUN_081df8a0
	ldr r1, _081DD5C0 @ =FUN_081dd3c8
	movs r2, #4
	ldr r3, _081DD5C4 @ =0x00000838
	adds r0, r6, r3
	str r1, [r0]
	ldr r1, _081DD5C8 @ =0x00000855
	adds r0, r6, r1
	strb r5, [r0]
	adds r3, #0x1c
	adds r0, r6, r3
	strb r2, [r0]
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DD5FC
	movs r0, #0xdd
	bl PlaySound_082406e0
	b _081DD620
	.align 2, 0
_081DD5BC: .4byte 0x0000085A
_081DD5C0: .4byte FUN_081dd3c8
_081DD5C4: .4byte 0x00000838
_081DD5C8: .4byte 0x00000855
_081DD5CC:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _081DD610
	movs r0, #0xc4
	lsls r0, r0, #3
	adds r1, r6, r0
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	movs r0, #0
	bl FUN_081df8a0
	ldr r1, _081DD604 @ =FUN_081dd3c8
	movs r2, #4
	ldr r3, _081DD608 @ =0x00000838
	adds r0, r6, r3
	str r1, [r0]
	ldr r1, _081DD60C @ =0x00000855
	adds r0, r6, r1
	strb r5, [r0]
	adds r3, #0x1c
	adds r0, r6, r3
	strb r2, [r0]
_081DD5FC:
	movs r0, #0xde
	bl PlaySound_082406e0
	b _081DD620
	.align 2, 0
_081DD604: .4byte FUN_081dd3c8
_081DD608: .4byte 0x00000838
_081DD60C: .4byte 0x00000855
_081DD610:
	movs r1, #0xc3
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r2, #0xd3
	lsls r2, r2, #3
	adds r1, r6, r2
	bl MainSprite_AdvanceAnim
_081DD620:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

	thumb_func_start FUN_081dd628
FUN_081dd628: @ 0x081DD628
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081DD660 @ =0x00000855
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _081DD648
	adds r0, r4, #0
	bl FUN_081dd36c
	ldr r1, _081DD664 @ =0x00000856
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r5]
_081DD648:
	adds r0, r4, #0
	bl FUN_081dcf34
	ldr r3, _081DD664 @ =0x00000856
	adds r1, r4, r3
	ldrh r0, [r1]
	cmp r0, #9
	bhi _081DD668
	adds r0, #1
	strh r0, [r1]
	b _081DD692
	.align 2, 0
_081DD660: .4byte 0x00000855
_081DD664: .4byte 0x00000856
_081DD668:
	ldr r0, _081DD698 @ =0x030044E0
	ldrh r1, [r0, #2]
	movs r0, #9
	ands r0, r1
	cmp r0, #0
	beq _081DD692
	movs r0, #0xdd
	bl PlaySound_082406e0
	ldr r1, _081DD69C @ =FUN_081dd434
	movs r2, #3
	ldr r3, _081DD6A0 @ =0x00000838
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081DD6A4 @ =0x00000855
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD6A8 @ =0x00000854
	adds r0, r4, r1
	strb r2, [r0]
_081DD692:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD698: .4byte 0x030044E0
_081DD69C: .4byte FUN_081dd434
_081DD6A0: .4byte 0x00000838
_081DD6A4: .4byte 0x00000855
_081DD6A8: .4byte 0x00000854

	thumb_func_start FUN_081dd6ac
FUN_081dd6ac: @ 0x081DD6AC
	push {r4, r5, lr}
	adds r4, r0, #0
	ldr r0, _081DD738 @ =0x00000855
	adds r3, r4, r0
	ldrb r0, [r3]
	cmp r0, #0
	beq _081DD6C6
	ldr r1, _081DD73C @ =0x00000856
	adds r0, r4, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r3]
_081DD6C6:
	ldr r0, _081DD740 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081DD744 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081DD6FC
	movs r2, #0
	ldr r3, _081DD748 @ =0x00000859
	adds r1, r4, r3
	movs r0, #0
	ldrsb r0, [r1, r0]
	cmp r2, r0
	bge _081DD6FC
	movs r5, #1
	adds r3, r1, #0
	ldr r0, _081DD74C @ =0x000006EC
	adds r1, r4, r0
_081DD6E8:
	ldrh r0, [r1]
	cmp r0, #1
	bls _081DD6F0
	strh r5, [r1]
_081DD6F0:
	adds r1, #2
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r3, r0]
	cmp r2, r0
	blt _081DD6E8
_081DD6FC:
	adds r0, r4, #0
	bl FUN_081dccec
	adds r0, r4, #0
	bl FUN_081dd1d8
	ldr r1, _081DD750 @ =0x00000858
	adds r0, r4, r1
	ldrb r1, [r0]
	ldr r2, _081DD748 @ =0x00000859
	adds r0, r4, r2
	ldrb r0, [r0]
	lsls r0, r0, #0x18
	asrs r0, r0, #0x18
	cmp r1, r0
	blt _081DD760
	ldr r1, _081DD754 @ =FUN_081dd628
	movs r2, #2
	ldr r3, _081DD758 @ =0x00000838
	adds r0, r4, r3
	str r1, [r0]
	ldr r0, _081DD738 @ =0x00000855
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD75C @ =0x00000854
	adds r0, r4, r1
	strb r2, [r0]
	b _081DD76A
	.align 2, 0
_081DD738: .4byte 0x00000855
_081DD73C: .4byte 0x00000856
_081DD740: .4byte 0x030044E0
_081DD744: .4byte 0x0000030F
_081DD748: .4byte 0x00000859
_081DD74C: .4byte 0x000006EC
_081DD750: .4byte 0x00000858
_081DD754: .4byte FUN_081dd628
_081DD758: .4byte 0x00000838
_081DD75C: .4byte 0x00000854
_081DD760:
	ldr r2, _081DD770 @ =0x00000856
	adds r1, r4, r2
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
_081DD76A:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081DD770: .4byte 0x00000856

	thumb_func_start FUN_081dd774
FUN_081dd774: @ 0x081DD774
	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	ldr r0, _081DD7EC @ =0x00000855
	adds r4, r3, r0
	ldrb r0, [r4]
	cmp r0, #0
	beq _081DD792
	ldr r1, _081DD7F0 @ =0x00000856
	adds r0, r3, r1
	movs r2, #0
	movs r1, #0
	strh r1, [r0]
	strb r2, [r4]
_081DD792:
	ldr r2, _081DD7F0 @ =0x00000856
	adds r0, r3, r2
	ldrh r0, [r0]
	cmp r0, #0xa
	bls _081DD80C
	ldr r0, _081DD7F4 @ =0x030044E0
	ldrh r1, [r0, #2]
	ldr r0, _081DD7F8 @ =0x0000030F
	ands r0, r1
	cmp r0, #0
	beq _081DD80C
	movs r2, #0
	ldr r4, _081DD7FC @ =0x00000859
	adds r1, r3, r4
	movs r0, #0
	ldrsb r0, [r1, r0]
	ldr r4, _081DD800 @ =FUN_081dd6ac
	mov r8, r4
	ldr r4, _081DD804 @ =0x00000838
	adds r4, r4, r3
	mov ip, r4
	ldr r4, _081DD7EC @ =0x00000855
	adds r7, r3, r4
	subs r4, #1
	adds r6, r3, r4
	cmp r2, r0
	bge _081DD7DE
	movs r5, #1
	adds r4, r1, #0
	ldr r0, _081DD808 @ =0x000006EC
	adds r1, r3, r0
_081DD7D0:
	strh r5, [r1]
	adds r1, #2
	adds r2, #1
	movs r0, #0
	ldrsb r0, [r4, r0]
	cmp r2, r0
	blt _081DD7D0
_081DD7DE:
	movs r0, #1
	mov r1, r8
	mov r2, ip
	str r1, [r2]
	strb r0, [r7]
	strb r0, [r6]
	b _081DD84C
	.align 2, 0
_081DD7EC: .4byte 0x00000855
_081DD7F0: .4byte 0x00000856
_081DD7F4: .4byte 0x030044E0
_081DD7F8: .4byte 0x0000030F
_081DD7FC: .4byte 0x00000859
_081DD800: .4byte FUN_081dd6ac
_081DD804: .4byte 0x00000838
_081DD808: .4byte 0x000006EC
_081DD80C:
	ldr r0, _081DD830 @ =0x00000856
	adds r4, r3, r0
	ldrh r0, [r4]
	cmp r0, #0x40
	bls _081DD840
	ldr r1, _081DD834 @ =FUN_081dd6ac
	movs r2, #1
	ldr r4, _081DD838 @ =0x00000838
	adds r0, r3, r4
	str r1, [r0]
	ldr r1, _081DD83C @ =0x00000855
	adds r0, r3, r1
	strb r2, [r0]
	adds r4, #0x1c
	adds r0, r3, r4
	strb r2, [r0]
	b _081DD84C
	.align 2, 0
_081DD830: .4byte 0x00000856
_081DD834: .4byte FUN_081dd6ac
_081DD838: .4byte 0x00000838
_081DD83C: .4byte 0x00000855
_081DD840:
	adds r0, r3, #0
	bl FUN_081dccec
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
_081DD84C:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	thumb_func_start EntityB85F_Update
EntityB85F_Update: @ 0x081DD858
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dfa04
	cmp r0, #0
	bne _081DD870
	adds r0, r4, #0
	bl KillEntity
	movs r0, #1
	rsbs r0, r0, #0
	b _081DD882
_081DD870:
	ldr r1, _081DD888 @ =0x00000838
	adds r0, r4, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081DD880
	adds r0, r4, #0
	bl _call_via_r1
_081DD880:
	movs r0, #1
_081DD882:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_081DD888: .4byte 0x00000838

	thumb_func_start EntityB85F_Destroy
EntityB85F_Destroy: @ 0x081DD88C
	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081dc880
	adds r0, r4, #0
	bl FUN_081dcb70
	movs r0, #1
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityB85F_Init
EntityB85F_Init: @ 0x081DD8A4
	push {r4, r5, lr}
	adds r4, r0, #0
	movs r0, #0x73
	bl VM_SeekToKeyword
	cmp r0, #0
	beq _081DD8C0
	bl FUN_0823d340
	ldr r2, _081DD934 @ =0x0000083C
	adds r1, r4, r2
	str r0, [r1]
	cmp r0, #0
	beq _081DD954
_081DD8C0:
	movs r0, #0
	bl FUN_081df8f0
	ldr r0, _081DD938 @ =0x03002C68
	ldr r0, [r0]
	movs r1, #1
	rsbs r1, r1, #0
	cmp r0, #0
	beq _081DD8D4
	ldrh r1, [r0, #0x1a]
_081DD8D4:
	ldr r2, _081DD93C @ =0x00000859
	adds r0, r4, r2
	movs r5, #0
	strb r1, [r0]
	lsls r0, r1, #0x18
	cmp r0, #0
	blt _081DD954
	adds r0, r4, #0
	bl FUN_081dc6d0
	adds r0, r4, #0
	bl FUN_081dc788
	adds r0, r4, #0
	bl FUN_081dc9dc
	adds r0, r4, #0
	bl FUN_081dcaa4
	adds r0, r4, #0
	bl FUN_081dcd50
	adds r0, r4, #0
	movs r1, #0x20
	bl FUN_081dce14
	ldr r1, _081DD940 @ =0x00000858
	adds r0, r4, r1
	strb r5, [r0]
	adds r0, r4, #0
	bl FUN_081dd2dc
	ldr r1, _081DD944 @ =FUN_081dd774
	ldr r2, _081DD948 @ =0x00000838
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, _081DD94C @ =0x00000855
	adds r1, r4, r0
	movs r0, #1
	strb r0, [r1]
	ldr r1, _081DD950 @ =0x00000854
	adds r0, r4, r1
	strb r5, [r0]
	movs r0, #7
	bl FUN_0809c08c
	movs r0, #1
	b _081DD958
	.align 2, 0
_081DD934: .4byte 0x0000083C
_081DD938: .4byte 0x03002C68
_081DD93C: .4byte 0x00000859
_081DD940: .4byte 0x00000858
_081DD944: .4byte FUN_081dd774
_081DD948: .4byte 0x00000838
_081DD94C: .4byte 0x00000855
_081DD950: .4byte 0x00000854
_081DD954:
	movs r0, #1
	rsbs r0, r0, #0
_081DD958:
	pop {r4, r5}
	pop {r1}
	bx r1
	.align 2, 0

	thumb_func_start EntityB85F_Create
EntityB85F_Create: @ 0x081DD960
	push {r4, lr}
	ldr r1, _081DD98C @ =0x0000085C
	movs r0, #0xb
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _081DD998
	ldr r1, _081DD990 @ =EntityB85F_Update
	ldr r2, _081DD994 @ =EntityB85F_Destroy
	bl SetEntityRoutine
	adds r0, r4, #0
	bl EntityB85F_Init
	cmp r0, #0
	bge _081DD998
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _081DD99A
	.align 2, 0
_081DD98C: .4byte 0x0000085C
_081DD990: .4byte EntityB85F_Update
_081DD994: .4byte EntityB85F_Destroy
_081DD998:
	adds r0, r4, #0
_081DD99A:
	pop {r4}
	pop {r1}
	bx r1

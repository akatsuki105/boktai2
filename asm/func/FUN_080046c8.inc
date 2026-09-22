	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0x24
	mov sl, r0
	adds r5, r1, #0
	adds r6, r2, #0
	mov sb, r3
	ldr r0, _080046F8 @ =0x03000020
	ldr r4, [r0]
	cmp r4, #0
	beq _080046F0
	adds r0, r4, #0
	bl FUN_08004668
	adds r7, r0, #0
	cmp r7, #0
	bne _080046FC
_080046F0:
	movs r0, #1
	rsbs r0, r0, #0
	b _080049F4
	.align 2, 0
_080046F8: .4byte 0x03000020
_080046FC:
	movs r1, #0xce
	lsls r1, r1, #1
	adds r0, r7, #0
	bl ClearMemory
	movs r2, #0
	movs r1, #1
	strb r1, [r7, #0x1e]
	strb r5, [r7]
	lsls r0, r5, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #6
	bne _08004718
	strb r1, [r4, #0x1e]
_08004718:
	strb r6, [r7, #1]
	strh r2, [r7, #2]
	strh r2, [r7, #4]
	adds r6, r7, #0
	adds r6, #0x70
	adds r0, r6, #0
	ldr r1, [sp, #0x44]
	bl Video_GetAuxSprite
	adds r4, r7, #0
	adds r4, #0x8c
	adds r0, r4, #0
	adds r1, r6, #0
	movs r2, #0
	bl AuxSprite_Add
	ldr r0, [sp, #0x48]
	strh r0, [r4, #0x10]
	movs r0, #0xa8
	adds r0, r0, r7
	mov r8, r0
	mov r2, sb
	ldr r0, [r2]
	ldr r1, [r2, #4]
	mov r3, r8
	str r0, [r3]
	str r1, [r3, #4]
	adds r5, r7, #0
	adds r5, #0x2c
	mov r0, sl
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	movs r0, #7
	str r0, [sp]
	str r7, [sp, #4]
	adds r0, r5, #0
	movs r3, #0
	bl FUN_0823b400
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_0823b46c
	mov r2, r8
	ldr r0, [r2]
	ldr r1, [r2, #4]
	str r0, [r7, #0x34]
	str r1, [r7, #0x38]
	movs r1, #0x10
	ldrb r0, [r7, #1]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r6, [sp, #0x20]
	str r5, [sp, #0x1c]
	cmp r0, #0
	beq _08004798
	subs r4, #0x58
	adds r0, r4, #0
	bl FUN_08241574
	str r0, [r7, #8]
	mov sl, r4
	b _080047A0
_08004798:
	str r0, [r7, #8]
	movs r3, #0x34
	adds r3, r3, r7
	mov sl, r3
_080047A0:
	movs r0, #0
	movs r3, #0
	strh r3, [r7, #0xc]
	strh r3, [r7, #0xe]
	strb r0, [r7, #0x10]
	movs r1, #4
	ldrb r0, [r7, #1]
	ands r0, r1
	lsls r0, r0, #0x10
	lsrs r2, r0, #0x10
	cmp r2, #0
	beq _080047CC
	ldr r0, _080047C8 @ =0x080042B9
	movs r2, #0xcc
	lsls r2, r2, #1
	adds r1, r7, r2
	str r0, [r1]
	strh r3, [r7, #2]
	b _080047D8
	.align 2, 0
_080047C8: .4byte 0x080042B9
_080047CC:
	ldr r0, _08004808 @ =FUN_08003f38
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r7, r3
	str r0, [r1]
	strh r2, [r7, #2]
_080047D8:
	movs r0, #1
	strb r0, [r7, #0x11]
	ldrh r0, [r7, #0x34]
	lsls r0, r0, #0x10
	asrs r2, r0, #0x18
	mov r1, sl
	ldrh r0, [r1, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r2, #0
	blt _08004802
	cmp r1, #0
	blt _08004802
	ldr r0, _0800480C @ =0x030046A8
	ldr r0, [r0]
	cmp r2, r0
	bhs _08004802
	ldr r0, _08004810 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _08004814
_08004802:
	movs r5, #0
	b _08004822
	.align 2, 0
_08004808: .4byte FUN_08003f38
_0800480C: .4byte 0x030046A8
_08004810: .4byte 0x030046AC
_08004814:
	ldr r0, _08004834 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r5, r0, r2
_08004822:
	adds r0, r5, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _08004838
	adds r0, #4
	b _08004844
	.align 2, 0
_08004834: .4byte 0x030046A4
_08004838:
	ldr r0, _08004964 @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r5, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_08004844:
	ldrb r0, [r0]
	movs r4, #0xf
	ands r4, r0
	cmp r4, #0xe
	bgt _08004850
	adds r4, #1
_08004850:
	adds r0, r7, #0
	adds r0, #0xb8
	movs r1, #0xff
	str r1, [sp]
	movs r2, #0
	mov sb, r2
	str r2, [sp, #4]
	adds r1, r5, #0
	adds r3, r4, #0
	bl FUN_08234270
	lsls r0, r4, #8
	movs r6, #0
	strh r0, [r7, #0x12]
	ldr r2, _08004968 @ =0xFFFF0000
	ldr r0, [sp, #0xc]
	ands r0, r2
	movs r3, #0x82
	orrs r0, r3
	ldr r1, _0800496C @ =0x0000FFFF
	ands r0, r1
	movs r1, #0x80
	lsls r1, r1, #0x10
	orrs r0, r1
	str r0, [sp, #0xc]
	add r0, sp, #0xc
	mov r8, r0
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r3
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	add r5, sp, #0x14
	ldr r0, [r5, #4]
	ands r0, r2
	str r0, [r5, #4]
	adds r4, r7, #0
	adds r4, #0xc8
	ldrh r1, [r7, #0x2c]
	ldr r2, _08004970 @ =0x00004041
	movs r0, #0x10
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _08004974 @ =FUN_080034c8
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	adds r0, r4, #0
	bl Hitbox_Register
	movs r0, #0x80
	add r1, sp, #0xc
	strh r0, [r1]
	mov r1, r8
	strh r0, [r1, #2]
	strh r0, [r1, #4]
	movs r2, #0x8c
	lsls r2, r2, #1
	adds r4, r7, r2
	ldrh r1, [r7, #0x2c]
	ldr r2, _08004978 @ =0x00002801
	movs r0, #1
	str r0, [sp]
	add r3, sp, #0xc
	str r3, [sp, #4]
	str r5, [sp, #8]
	adds r0, r4, #0
	movs r3, #0
	bl Hitbox_Init
	adds r0, r4, #0
	mov r1, sl
	movs r2, #0
	bl Hitbox_SetPos
	ldr r1, _0800497C @ =FUN_080035e0
	adds r0, r4, #0
	adds r2, r7, #0
	bl Hitbox_SetHandler
	ldr r1, _08004980 @ =0x000005DC
	adds r0, r4, #0
	movs r2, #0x32
	bl Hitbox_SetPower
	movs r0, #0x80
	lsls r0, r0, #1
	str r0, [r4, #0x34]
	mov r0, sb
	str r0, [r4, #0x38]
	ldr r0, [sp, #0x4c]
	strh r0, [r7, #0x16]
	strb r6, [r7, #0x18]
	strb r6, [r7, #0x19]
	strb r6, [r7, #0x1f]
	adds r0, r7, #0
	adds r0, #0x20
	strb r6, [r0]
	adds r0, #1
	strb r6, [r0]
	adds r1, r7, #0
	adds r1, #0x23
	movs r0, #4
	strb r0, [r1]
	ldr r2, _08004984 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _08004988 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _0800498C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #0x10
	bl Mod
	adds r1, r7, #0
	adds r1, #0x22
	strb r0, [r1]
	ldr r2, [sp, #0x50]
	cmp r2, #0
	blt _08004990
	strh r2, [r7, #0x1a]
	b _08004998
	.align 2, 0
_08004964: .4byte 0x030046A4
_08004968: .4byte 0xFFFF0000
_0800496C: .4byte 0x0000FFFF
_08004970: .4byte 0x00004041
_08004974: .4byte FUN_080034c8
_08004978: .4byte 0x00002801
_0800497C: .4byte FUN_080035e0
_08004980: .4byte 0x000005DC
_08004984: .4byte 0x030046B8
_08004988: .4byte 0x000003FF
_0800498C: .4byte 0x0203B400
_08004990:
	adds r0, r7, #0
	adds r0, #0x76
	ldrh r0, [r0]
	strh r0, [r7, #0x1a]
_08004998:
	ldrh r1, [r7, #0x1a]
	ldr r0, [sp, #0x20]
	bl Video_SetAuxSpritePltt
	ldr r0, [sp, #0x54]
	strh r0, [r7, #0x1c]
	ldrh r1, [r7, #0x2c]
	movs r2, #0xb4
	lsls r2, r2, #1
	adds r0, r7, r2
	strh r1, [r0]
	movs r3, #0xb6
	lsls r3, r3, #1
	adds r0, r7, r3
	mov r1, sl
	str r1, [r0]
	ldr r0, [sp, #0x58]
	str r0, [r7, #0x28]
	ldrb r1, [r7, #1]
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	bne _080049D8
	ldr r0, [sp, #0x1c]
	bl FUN_08002a48
	cmp r0, #0
	bge _080049D8
	ldrb r1, [r7, #1]
	movs r0, #2
	orrs r0, r1
	strb r0, [r7, #1]
_080049D8:
	ldrb r0, [r7]
	cmp r0, #5
	bne _080049E6
	adds r0, r7, #0
	adds r0, #0x24
	movs r1, #1
	b _080049EC
_080049E6:
	adds r0, r7, #0
	adds r0, #0x24
	movs r1, #0
_080049EC:
	strb r1, [r0]
	adds r0, #1
	strb r1, [r0]
	movs r0, #0
_080049F4:
	add sp, #0x24
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

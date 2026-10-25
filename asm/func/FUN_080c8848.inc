	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0xc
	mov r8, r0
	mov sb, r1
	mov r5, r8
	adds r7, r5, #0
	adds r7, #0xa9
	ldrb r0, [r7]
	cmp r0, #0
	beq _080C889E
	movs r4, #0
	strb r4, [r7]
	ldr r0, _080C8908 @ =0x03002BE0
	ldr r1, [r0]
	movs r2, #0x2c
	ldrsh r0, [r1, r2]
	ldr r2, _080C890C @ =0xFFFFFAEC
	adds r0, r0, r2
	movs r2, #0x30
	ldrsh r1, [r1, r2]
	ldr r2, _080C8910 @ =0xFFFFFE00
	adds r1, r1, r2
	bl ArcTan2_8
	ldr r2, _080C8914 @ =0x000025EE
	adds r1, r5, r2
	strh r0, [r1]
	movs r1, #0xd2
	lsls r1, r1, #3
	adds r0, r5, r1
	movs r1, #2
	str r1, [sp]
	str r4, [sp, #4]
	movs r1, #4
	str r1, [sp, #8]
	movs r1, #0x32
	movs r2, #0
	movs r3, #0
	bl SpriteHolder_SetAnim
_080C889E:
	adds r0, r5, #0
	adds r0, #0xfc
	ldr r1, [r0]
	adds r0, r5, #0
	bl _call_via_r1
	lsls r0, r0, #0x18
	lsrs r6, r0, #0x18
	cmp r6, #0
	bne _080C897A
	movs r2, #0x80
	lsls r2, r2, #0x18
	adds r1, r5, #0
	adds r1, #0x98
	ldr r0, [r1]
	orrs r0, r2
	str r0, [r1]
	mov r2, sb
	cmp r2, #5
	bne _080C88D4
	ldr r1, _080C8914 @ =0x000025EE
	adds r0, r5, r1
	ldrh r2, [r0]
	adds r0, r5, #0
	movs r1, #0
	bl FUN_080c35f0
_080C88D4:
	mov r2, sb
	cmp r2, #0x59
	ble _080C897A
	ldr r0, _080C8918 @ =0x000025EC
	adds r1, r5, r0
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #3
	bls _080C8920
	ldr r1, _080C891C @ =FUN_080c8c4c
	movs r0, #0x1a
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	movs r0, #1
	strb r0, [r7]
	b _080C897A
	.align 2, 0
_080C8908: .4byte 0x03002BE0
_080C890C: .4byte 0xFFFFFAEC
_080C8910: .4byte 0xFFFFFE00
_080C8914: .4byte 0x000025EE
_080C8918: .4byte 0x000025EC
_080C891C: .4byte FUN_080c8c4c
_080C8920:
	ldr r2, _080C8954 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080C8958 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080C895C @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	asrs r3, r0, #3
	movs r4, #1
	ands r3, r4
	cmp r3, #0
	beq _080C8964
	ldr r1, _080C8960 @ =FUN_080c87c8
	movs r0, #0x15
	adds r2, r5, #0
	adds r2, #0xa3
	strb r0, [r2]
	adds r0, r5, #0
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r6, [r0]
	b _080C8978
	.align 2, 0
_080C8954: .4byte 0x030046B8
_080C8958: .4byte 0x000003FF
_080C895C: .4byte 0x0203B400
_080C8960: .4byte FUN_080c87c8
_080C8964:
	ldr r1, _080C8988 @ =FUN_080c8aa8
	movs r0, #0x18
	mov r2, r8
	adds r2, #0xa3
	strb r0, [r2]
	mov r0, r8
	adds r0, #0xf8
	str r1, [r0]
	subs r0, #0x6c
	str r3, [r0]
_080C8978:
	strb r4, [r7]
_080C897A:
	add sp, #0xc
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080C8988: .4byte FUN_080c8aa8

	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x10
	mov sb, r0
	adds r6, r1, #0
	adds r5, r2, #0
	adds r7, r5, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _0811637A
	b _08116616
_0811637A:
	mov r2, sb
	ldr r0, [r2, #0x24]
	ldr r1, [r2, #0x28]
	str r0, [sp]
	str r1, [sp, #4]
	ldrb r0, [r5, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _081163B4
	cmp r0, #1
	bgt _0811639C
	cmp r0, #0
	beq _081163A6
	b _081163FC
_0811639C:
	cmp r0, #2
	beq _081163C4
	cmp r0, #3
	beq _081163E4
	b _081163FC
_081163A6:
	mov r0, sp
	ldrh r1, [r0]
	ldr r3, _081163B0 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081163CE
	.align 2, 0
_081163B0: .4byte 0xFFFFFF00
_081163B4:
	mov r0, sp
	ldrh r1, [r0, #4]
	ldr r0, _081163C0 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081163EE
	.align 2, 0
_081163C0: .4byte 0xFFFFFF00
_081163C4:
	mov r0, sp
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081163CE:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081163E0 @ =0xFFFF0000
	ldr r0, [sp]
	ands r0, r2
	orrs r0, r1
	str r0, [sp]
	b _081163FC
	.align 2, 0
_081163E0: .4byte 0xFFFF0000
_081163E4:
	mov r0, sp
	ldrh r1, [r0, #4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_081163EE:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0811647C @ =0xFFFF0000
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
_081163FC:
	add r2, sp, #8
	mov r4, sp
	adds r3, r6, #0
	adds r3, #0x24
	ldrh r0, [r6, #0x24]
	mov r1, sp
	ldrh r1, [r1]
	subs r0, r0, r1
	strh r0, [r2]
	ldrh r0, [r3, #2]
	ldrh r1, [r4, #2]
	subs r0, r0, r1
	strh r0, [r2, #2]
	ldrh r0, [r3, #4]
	ldrh r1, [r4, #4]
	subs r0, r0, r1
	strh r0, [r2, #4]
	movs r1, #0
	ldrsh r0, [r2, r1]
	movs r3, #4
	ldrsh r1, [r2, r3]
	bl ArcTan2_8
	mov r1, sb
	adds r1, #0x42
	strb r0, [r1]
	ldrh r1, [r6, #0xa]
	movs r4, #0xf
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	bne _0811643E
	b _081165E8
_0811643E:
	movs r1, #0x80
	lsls r1, r1, #1
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r7, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _08116452
	b _08116598
_08116452:
	ldr r3, _08116480 @ =0x00000553
	adds r0, r7, r3
	ldrb r0, [r0]
	cmp r0, #0x28
	beq _081164BE
	ldrb r2, [r7, #5]
	ldr r0, [r6, #0x4c]
	movs r1, #8
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	beq _081164B4
	adds r1, r2, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _08116484
	asrs r0, r1, #6
	b _0811648A
	.align 2, 0
_0811647C: .4byte 0xFFFF0000
_08116480: .4byte 0x00000553
_08116484:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_0811648A:
	adds r2, r0, #0
	adds r0, r6, #0
	adds r0, #0x42
	ldrb r0, [r0]
	adds r1, r0, #0
	adds r1, #0x20
	movs r0, #0xff
	ands r1, r0
	cmp r1, #0
	blt _081164A2
	asrs r0, r1, #6
	b _081164A8
_081164A2:
	rsbs r0, r1, #0
	asrs r0, r0, #6
	rsbs r0, r0, #0
_081164A8:
	subs r0, r2, r0
	cmp r0, #0
	bge _081164B0
	rsbs r0, r0, #0
_081164B0:
	cmp r0, #2
	bne _081164B8
_081164B4:
	movs r0, #1
	b _081164BA
_081164B8:
	movs r0, #0
_081164BA:
	cmp r0, #0
	beq _08116524
_081164BE:
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081164EC
	ldrh r1, [r6, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081164EC
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _0811651C @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081164EC:
	ldr r1, _08116520 @ =0x000006BC
	add r1, r8
	ldrh r0, [r1]
	adds r0, #0xc8
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _08116504
	strh r2, [r1]
_08116504:
	adds r2, r6, #0
	adds r2, #0x46
	ldrb r1, [r2]
	movs r0, #1
	orrs r0, r1
	strb r0, [r2]
	ldrh r1, [r6, #4]
	movs r0, #0xcd
	lsls r0, r0, #3
	add r0, r8
	strh r1, [r0]
	b _08116616
	.align 2, 0
_0811651C: .4byte 0xFEFFFFFF
_08116520: .4byte 0x000006BC
_08116524:
	ldr r0, _08116538 @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _0811653C
	movs r0, #1
	b _0811653E
	.align 2, 0
_08116538: .4byte 0x030047A4
_0811653C:
	movs r0, #0
_0811653E:
	cmp r0, #0
	beq _08116574
	ldrh r1, [r6, #0xa]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _08116550
	movs r2, #0
	b _08116568
_08116550:
	movs r0, #2
	ands r0, r1
	cmp r0, #0
	beq _0811655C
	movs r2, #1
	b _08116568
_0811655C:
	movs r0, #4
	ands r0, r1
	movs r2, #3
	cmp r0, #0
	beq _08116568
	movs r2, #2
_08116568:
	ldr r1, _08116570 @ =0x03002BE0
	lsls r0, r2, #2
	adds r0, r0, r1
	b _08116576
	.align 2, 0
_08116570: .4byte 0x03002BE0
_08116574:
	ldr r0, _08116590 @ =0x03002BE0
_08116576:
	ldr r0, [r0]
	movs r1, #0x80
	lsls r1, r1, #0xa
	ldr r0, [r0, #0x20]
	ands r0, r1
	cmp r0, #0
	bne _08116616
	ldr r1, _08116594 @ =0x000006BC
	add r1, r8
	movs r0, #0xc8
	lsls r0, r0, #1
	strh r0, [r1]
	b _08116616
	.align 2, 0
_08116590: .4byte 0x03002BE0
_08116594: .4byte 0x000006BC
_08116598:
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081165C6
	ldrh r1, [r6, #0xa]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _081165C6
	movs r2, #0xea
	lsls r2, r2, #1
	adds r1, r5, r2
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r3, #0xbe
	lsls r3, r3, #1
	adds r2, r5, r3
	ldr r1, _081165E0 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081165C6:
	ldr r1, _081165E4 @ =0x000006BC
	add r1, r8
	ldrh r0, [r1]
	adds r0, #0xc8
	strh r0, [r1]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	movs r2, #0xc8
	lsls r2, r2, #1
	cmp r0, r2
	bls _08116616
	strh r2, [r1]
	b _08116616
	.align 2, 0
_081165E0: .4byte 0xFEFFFFFF
_081165E4: .4byte 0x000006BC
_081165E8:
	adds r0, r5, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08116616
	ldrh r1, [r6, #0xa]
	adds r0, r4, #0
	ands r0, r1
	cmp r0, #0
	beq _08116616
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r5, r0
	ldrh r0, [r6, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r5, r1
	ldr r1, _08116624 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_08116616:
	add sp, #0x10
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08116624: .4byte 0xFEFFFFFF

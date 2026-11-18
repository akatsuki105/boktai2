	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x28
	mov sb, r0
	adds r5, r1, #0
	adds r6, r2, #0
	adds r7, r6, #0
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r0, [r0]
	mov r8, r0
	adds r0, r6, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	beq _081C75EE
	b _081C78DE
_081C75EE:
	mov r2, sb
	ldr r0, [r2, #0x24]
	ldr r1, [r2, #0x28]
	str r0, [sp, #0x10]
	str r1, [sp, #0x14]
	ldrb r0, [r6, #5]
	adds r0, #0x20
	movs r1, #0xff
	ands r0, r1
	asrs r0, r0, #6
	cmp r0, #1
	beq _081C7628
	cmp r0, #1
	bgt _081C7610
	cmp r0, #0
	beq _081C761A
	b _081C7670
_081C7610:
	cmp r0, #2
	beq _081C7638
	cmp r0, #3
	beq _081C7658
	b _081C7670
_081C761A:
	add r0, sp, #0x10
	ldrh r1, [r0]
	ldr r3, _081C7624 @ =0xFFFFFF00
	adds r1, r1, r3
	b _081C7642
	.align 2, 0
_081C7624: .4byte 0xFFFFFF00
_081C7628:
	add r0, sp, #0x10
	ldrh r1, [r0, #4]
	ldr r0, _081C7634 @ =0xFFFFFF00
	adds r1, r1, r0
	b _081C7662
	.align 2, 0
_081C7634: .4byte 0xFFFFFF00
_081C7638:
	add r0, sp, #0x10
	ldrh r1, [r0]
	movs r2, #0x80
	lsls r2, r2, #1
	adds r1, r1, r2
_081C7642:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C7654 @ =0xFFFF0000
	ldr r0, [sp, #0x10]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x10]
	b _081C7670
	.align 2, 0
_081C7654: .4byte 0xFFFF0000
_081C7658:
	add r0, sp, #0x10
	ldrh r1, [r0, #4]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r1, r1, r3
_081C7662:
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _081C76E4 @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x14]
_081C7670:
	add r2, sp, #0x18
	add r4, sp, #0x10
	adds r3, r5, #0
	adds r3, #0x24
	ldrh r0, [r5, #0x24]
	adds r1, r4, #0
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
	adds r0, r7, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C76D2
	ldrh r1, [r5, #0xa]
	movs r0, #0xf
	ands r0, r1
	cmp r0, #0
	beq _081C76D2
	movs r0, #0xea
	lsls r0, r0, #1
	adds r1, r7, r0
	ldrh r0, [r5, #4]
	str r0, [r1]
	movs r1, #0xbe
	lsls r1, r1, #1
	adds r2, r7, r1
	ldr r1, _081C76E8 @ =0xFEFFFFFF
	ldr r0, [r2]
	ands r0, r1
	str r0, [r2]
_081C76D2:
	ldr r0, _081C76EC @ =0x030047A4
	ldr r0, [r0]
	movs r1, #0x90
	lsls r1, r1, #7
	ands r0, r1
	cmp r0, #0
	beq _081C76F0
	movs r0, #1
	b _081C76F2
	.align 2, 0
_081C76E4: .4byte 0xFFFF0000
_081C76E8: .4byte 0xFEFFFFFF
_081C76EC: .4byte 0x030047A4
_081C76F0:
	movs r0, #0
_081C76F2:
	cmp r0, #0
	beq _081C76F8
	b _081C78DE
_081C76F8:
	ldrh r0, [r5, #0xa]
	cmp r0, #1
	beq _081C7700
	b _081C78DE
_081C7700:
	movs r5, #0xda
	lsls r5, r5, #3
	add r5, r8
	movs r2, #0
	ldrsh r0, [r5, r2]
	cmp r0, #0
	blt _081C7710
	b _081C78DE
_081C7710:
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r6, r3
	ldrh r0, [r0]
	cmp r0, #0
	beq _081C7722
	cmp r0, #4
	beq _081C7722
	b _081C78DE
_081C7722:
	ldr r0, _081C7784 @ =0x03002BE0
	ldr r0, [r0]
	ldr r1, [r0, #0x30]
	ldr r0, [r0, #0x2c]
	str r0, [sp, #0x20]
	str r1, [sp, #0x24]
	ldr r2, [sp, #0x20]
	asrs r1, r2, #0x10
	adds r1, #0xc8
	lsls r1, r1, #0x10
	ldr r0, _081C7788 @ =0x0000FFFF
	mov sb, r0
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #0x20]
	ldr r4, _081C778C @ =0x000006D2
	add r4, r8
	ldr r2, _081C7790 @ =0x000006D4
	add r2, r8
	adds r0, r5, #0
	adds r1, r4, #0
	bl PickItemToSteal
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _081C7758
	b _081C78DE
_081C7758:
	movs r2, #0
	ldrsh r1, [r4, r2]
	add r0, sp, #0x20
	str r0, [sp]
	adds r0, r6, #0
	adds r0, #8
	str r0, [sp, #4]
	movs r0, #0x18
	str r0, [sp, #8]
	str r7, [sp, #0xc]
	movs r0, #0
	movs r2, #3
	movs r3, #0
	bl ItemIconPopupManager_AddIcon
	cmp r0, #0
	bge _081C7794
	ldrh r1, [r5]
	mov r0, sb
	orrs r0, r1
	strh r0, [r5]
	b _081C78DE
	.align 2, 0
_081C7784: .4byte 0x03002BE0
_081C7788: .4byte 0x0000FFFF
_081C778C: .4byte 0x000006D2
_081C7790: .4byte 0x000006D4
_081C7794:
	movs r3, #0
	ldrsh r0, [r5, r3]
	bl RemoveItem
	movs r0, #0
	ldrsh r1, [r4, r0]
	cmp r1, #0xb
	beq _081C77B8
	cmp r1, #0xb
	bgt _081C77AE
	cmp r1, #8
	beq _081C77B8
	b _081C78DE
_081C77AE:
	cmp r1, #0xe
	beq _081C77B8
	cmp r1, #0x11
	beq _081C77B8
	b _081C78DE
_081C77B8:
	movs r1, #0x95
	lsls r1, r1, #2
	adds r0, r6, r1
	ldrh r1, [r0]
	ldr r0, _081C77E8 @ =0x000006D9
	add r0, r8
	ldrb r0, [r0]
	muls r0, r1, r0
	movs r1, #0x64
	bl Div
	adds r1, r0, #0
	movs r3, #0xc2
	lsls r3, r3, #1
	adds r2, r6, r3
	movs r3, #0
	ldrsh r0, [r2, r3]
	subs r0, r0, r1
	cmp r0, #0
	bgt _081C77F0
	ldrh r1, [r2]
	ldr r2, _081C77EC @ =0x0000048A
	adds r0, r6, r2
	b _081C77F4
	.align 2, 0
_081C77E8: .4byte 0x000006D9
_081C77EC: .4byte 0x0000048A
_081C77F0:
	ldr r3, _081C7870 @ =0x0000048A
	adds r0, r6, r3
_081C77F4:
	strh r1, [r0]
	movs r1, #0xda
	lsls r1, r1, #3
	add r1, r8
	ldr r0, _081C7874 @ =0x0000FFFF
	strh r0, [r1]
	movs r0, #0xec
	lsls r0, r0, #1
	adds r1, r6, r0
	ldr r4, _081C7878 @ =0x03002BE0
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [r1]
	movs r1, #0x94
	lsls r1, r1, #3
	adds r0, r6, r1
	movs r3, #1
	str r3, [r0]
	movs r2, #0x93
	lsls r2, r2, #3
	adds r0, r6, r2
	movs r1, #0
	str r1, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	subs r2, #4
	adds r0, r6, r2
	str r1, [r0]
	adds r2, #4
	adds r0, r6, r2
	str r1, [r0]
	ldr r1, _081C7870 @ =0x0000048A
	adds r0, r6, r1
	ldrh r0, [r0]
	movs r2, #0x8b
	lsls r2, r2, #1
	adds r1, r6, r2
	strh r0, [r1]
	movs r1, #0x8c
	lsls r1, r1, #1
	adds r0, r6, r1
	movs r2, #1
	strh r3, [r0]
	movs r3, #0x8e
	lsls r3, r3, #1
	adds r1, r6, r3
	movs r0, #0x1e
	strh r0, [r1]
	ldr r1, _081C787C @ =0x0000048C
	adds r0, r6, r1
	strb r2, [r0]
	movs r1, #2
	ldr r2, _081C7880 @ =0x00000474
	adds r0, r6, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _081C7884
	movs r0, #1
	b _081C7886
	.align 2, 0
_081C7870: .4byte 0x0000048A
_081C7874: .4byte 0x0000FFFF
_081C7878: .4byte 0x03002BE0
_081C787C: .4byte 0x0000048C
_081C7880: .4byte 0x00000474
_081C7884:
	movs r0, #0
_081C7886:
	cmp r0, #0
	beq _081C789A
	movs r3, #0xec
	lsls r3, r3, #1
	adds r1, r6, r3
	ldr r0, [r4]
	adds r0, #0x24
	str r0, [r1]
	adds r0, r1, #0
	b _081C78A6
_081C789A:
	movs r1, #0xec
	lsls r1, r1, #1
	adds r0, r6, r1
	ldr r1, [r0]
	cmp r1, #0
	beq _081C78DE
_081C78A6:
	ldr r1, [r0]
	movs r2, #8
	ldrsh r5, [r1, r2]
	movs r3, #8
	ldrsh r0, [r6, r3]
	subs r5, r5, r0
	movs r0, #0xc
	ldrsh r4, [r1, r0]
	movs r1, #0xc
	ldrsh r0, [r6, r1]
	subs r4, r4, r0
	adds r0, r5, #0
	adds r1, r4, #0
	bl ArcTan2_8
	movs r2, #0xfe
	lsls r2, r2, #1
	adds r1, r6, r2
	strb r0, [r1]
	movs r3, #0xf2
	lsls r3, r3, #1
	adds r2, r6, r3
	adds r0, r5, #0
	muls r0, r5, r0
	adds r1, r4, #0
	muls r1, r4, r1
	adds r0, r0, r1
	str r0, [r2]
_081C78DE:
	add sp, #0x28
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

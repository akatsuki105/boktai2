	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r6, r0, #0
	movs r1, #0x10
	ldrsh r0, [r6, r1]
	cmp r0, #0
	beq _080E8F98
	cmp r0, #0
	bge _080E8F80
	ldr r0, _080E8F78 @ =0xFFFF0000
	adds r1, r0, #0
	ands r1, r4
	ldr r2, _080E8F7C @ =0x0000FFE0
	b _080E8F88
	.align 2, 0
_080E8F78: .4byte 0xFFFF0000
_080E8F7C: .4byte 0x0000FFE0
_080E8F80:
	ldr r0, _080E8F94 @ =0xFFFF0000
	adds r1, r0, #0
	ands r1, r4
	movs r2, #0x20
_080E8F88:
	adds r4, r1, #0
	orrs r4, r2
	ands r5, r0
	ldrh r2, [r6, #0x14]
	b _080E8FC4
	.align 2, 0
_080E8F94: .4byte 0xFFFF0000
_080E8F98:
	movs r2, #0x14
	ldrsh r0, [r6, r2]
	ldrh r2, [r6, #0x14]
	cmp r0, #0
	beq _080E9068
	cmp r0, #0
	bge _080E8FB8
	ldr r0, _080E8FB0 @ =0xFFFF0000
	ands r4, r0
	ands r0, r5
	ldr r1, _080E8FB4 @ =0x0000FFE0
	b _080E8FC0
	.align 2, 0
_080E8FB0: .4byte 0xFFFF0000
_080E8FB4: .4byte 0x0000FFE0
_080E8FB8:
	ldr r0, _080E901C @ =0xFFFF0000
	ands r4, r0
	ands r0, r5
	movs r1, #0x20
_080E8FC0:
	adds r5, r0, #0
	orrs r5, r1
_080E8FC4:
	ldrh r0, [r6, #0x10]
	ldrh r7, [r6, #8]
	adds r0, r0, r7
	adds r0, r4, r0
	lsls r0, r0, #0x10
	ldr r3, _080E901C @ =0xFFFF0000
	ldrh r1, [r6, #0x12]
	ldrh r7, [r6, #0xa]
	adds r1, r1, r7
	lsls r1, r1, #0x10
	lsrs r0, r0, #0x10
	orrs r0, r1
	str r0, [sp]
	ldrh r0, [r6, #0xc]
	adds r1, r2, r0
	adds r1, r5, r1
	lsls r1, r1, #0x10
	lsrs r1, r1, #0x10
	mov r2, sp
	ldr r0, [sp, #4]
	ands r0, r3
	orrs r0, r1
	str r0, [sp, #4]
	mov r0, sp
	ldrh r0, [r0]
	lsls r0, r0, #0x10
	asrs r3, r0, #0x18
	ldrh r0, [r2, #4]
	lsls r0, r0, #0x10
	asrs r1, r0, #0x18
	cmp r3, #0
	blt _080E9018
	cmp r1, #0
	blt _080E9018
	ldr r0, _080E9020 @ =0x030046A8
	ldr r0, [r0]
	cmp r3, r0
	bhs _080E9018
	ldr r0, _080E9024 @ =0x030046AC
	ldr r0, [r0]
	cmp r1, r0
	blo _080E9028
_080E9018:
	movs r4, #0
	b _080E9036
	.align 2, 0
_080E901C: .4byte 0xFFFF0000
_080E9020: .4byte 0x030046A8
_080E9024: .4byte 0x030046AC
_080E9028:
	ldr r0, _080E9048 @ =0x030046A4
	ldr r0, [r0]
	lsls r1, r1, #1
	adds r0, #0x24
	adds r0, r0, r1
	ldrh r0, [r0]
	adds r4, r0, r3
_080E9036:
	adds r0, r4, #0
	movs r1, #1
	bl FUN_08234224
	cmp r0, #0
	beq _080E904C
	adds r0, #4
	b _080E9058
	.align 2, 0
_080E9048: .4byte 0x030046A4
_080E904C:
	ldr r0, _080E906C @ =0x030046A4
	ldr r1, [r0]
	lsls r0, r4, #2
	adds r0, #0xc
	ldr r1, [r1, #4]
	adds r0, r1, r0
_080E9058:
	ldrb r0, [r0]
	movs r1, #0xf
	ands r1, r0
	lsls r1, r1, #8
	movs r2, #0xa
	ldrsh r0, [r6, r2]
	cmp r0, r1
	blt _080E9070
_080E9068:
	movs r0, #0
	b _080E9072
	.align 2, 0
_080E906C: .4byte 0x030046A4
_080E9070:
	movs r0, #1
_080E9072:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

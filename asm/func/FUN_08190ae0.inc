	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	movs r1, #0xe6
	lsls r1, r1, #1
	adds r0, r0, r1
	ldr r5, [r0]
	movs r2, #0
	mov sl, r2
	ldr r7, _08190B2C @ =0x00000F36
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	bge _08190BEE
	movs r6, #0
	ldr r2, _08190B30 @ =0x0000076E
	adds r3, r5, r2
	adds r4, r5, #0
	movs r7, #2
	mov sb, r7
	movs r0, #1
	mov r8, r0
	movs r1, #0x92
	lsls r1, r1, #1
	mov ip, r1
_08190B18:
	adds r0, r6, r5
	ldr r2, _08190B34 @ =0x0000077A
	adds r0, r0, r2
	ldrh r0, [r0]
	mov r7, sb
	ands r0, r7
	cmp r0, #0
	beq _08190B38
	movs r0, #1
	b _08190B3A
	.align 2, 0
_08190B2C: .4byte 0x00000F36
_08190B30: .4byte 0x0000076E
_08190B34: .4byte 0x0000077A
_08190B38:
	movs r0, #0
_08190B3A:
	cmp r0, #0
	beq _08190BD8
	adds r0, r6, r5
	ldr r1, _08190B54 @ =0x0000077A
	adds r0, r0, r1
	ldrh r0, [r0]
	mov r2, r8
	ands r0, r2
	cmp r0, #0
	beq _08190B58
	movs r0, #1
	b _08190B5A
	.align 2, 0
_08190B54: .4byte 0x0000077A
_08190B58:
	movs r0, #0
_08190B5A:
	cmp r0, #0
	bne _08190BD8
	ldr r7, _08190B94 @ =0x00000674
	adds r1, r4, r7
	ldr r0, _08190B98 @ =0x0000076C
	adds r2, r4, r0
	ldrh r0, [r2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	ldr r0, _08190B9C @ =0x00000676
	adds r1, r4, r0
	ldrh r0, [r3]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	movs r0, #0xcf
	lsls r0, r0, #3
	adds r1, r4, r0
	ldrh r0, [r3, #2]
	ldrh r7, [r1]
	adds r0, r0, r7
	strh r0, [r1]
	movs r1, #0
	ldrsh r0, [r2, r1]
	cmp r0, #0
	blt _08190BA0
	asrs r1, r0, #1
	b _08190BA6
	.align 2, 0
_08190B94: .4byte 0x00000674
_08190B98: .4byte 0x0000076C
_08190B9C: .4byte 0x00000676
_08190BA0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r1, r0, #0
_08190BA6:
	ldr r2, _08190BB8 @ =0x0000076C
	adds r0, r4, r2
	strh r1, [r0]
	movs r7, #0
	ldrsh r0, [r3, r7]
	cmp r0, #0
	blt _08190BBC
	asrs r0, r0, #1
	b _08190BC2
	.align 2, 0
_08190BB8: .4byte 0x0000076C
_08190BBC:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08190BC2:
	strh r0, [r3]
	movs r1, #2
	ldrsh r0, [r3, r1]
	cmp r0, #0
	blt _08190BD0
	asrs r0, r0, #1
	b _08190BD6
_08190BD0:
	rsbs r0, r0, #0
	asrs r0, r0, #1
	rsbs r0, r0, #0
_08190BD6:
	strh r0, [r3, #2]
_08190BD8:
	add r6, ip
	add r3, ip
	add r4, ip
	movs r2, #1
	add sl, r2
	ldr r7, _08190BFC @ =0x00000F36
	adds r0, r5, r7
	movs r1, #0
	ldrsh r0, [r0, r1]
	cmp sl, r0
	blt _08190B18
_08190BEE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_08190BFC: .4byte 0x00000F36

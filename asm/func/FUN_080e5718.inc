	push {r4, r5, r6, r7, lr}
	mov r7, sb
	mov r6, r8
	push {r6, r7}
	sub sp, #0x24
	adds r5, r0, #0
	lsls r1, r1, #0x18
	lsrs r6, r1, #0x18
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	mov r8, r2
	lsls r3, r3, #0x18
	lsrs r7, r3, #0x18
	mov sb, r5
	cmp r2, #0x7f
	bne _080E57A0
	cmp r6, #1
	beq _080E5760
	cmp r6, #1
	bgt _080E5746
	cmp r6, #0
	beq _080E5750
	b _080E59B0
_080E5746:
	cmp r6, #2
	beq _080E5788
	cmp r6, #3
	beq _080E5770
	b _080E59B0
_080E5750:
	ldr r0, _080E575C @ =0x00000454
	adds r4, r5, r0
	ldr r0, [r4]
	ldrh r2, [r5]
	movs r1, #0
	b _080E5792
	.align 2, 0
_080E575C: .4byte 0x00000454
_080E5760:
	ldr r1, _080E576C @ =0x00000454
	adds r4, r5, r1
	ldr r0, [r4]
	ldrh r2, [r5]
	movs r1, #1
	b _080E5792
	.align 2, 0
_080E576C: .4byte 0x00000454
_080E5770:
	ldr r2, _080E5784 @ =0x00000454
	adds r4, r5, r2
	ldr r0, [r4]
	ldrh r2, [r5]
	movs r1, #3
	bl FUN_080d9a9c
	str r0, [r4]
	b _080E59B0
	.align 2, 0
_080E5784: .4byte 0x00000454
_080E5788:
	ldr r3, _080E579C @ =0x00000454
	adds r4, r5, r3
	ldr r0, [r4]
	ldrh r2, [r5]
	movs r1, #2
_080E5792:
	bl FUN_080d99d4
	str r0, [r4]
	b _080E59B0
	.align 2, 0
_080E579C: .4byte 0x00000454
_080E57A0:
	cmp r6, #1
	beq _080E586C
	cmp r6, #1
	bgt _080E57AE
	cmp r6, #0
	beq _080E57BC
	b _080E59B0
_080E57AE:
	cmp r6, #2
	bne _080E57B4
	b _080E5918
_080E57B4:
	cmp r6, #3
	bne _080E57BA
	b _080E5944
_080E57BA:
	b _080E59B0
_080E57BC:
	ldr r0, _080E5868 @ =0x00000454
	adds r4, r5, r0
	ldr r0, [r4]
	ldrh r2, [r5]
	movs r1, #0
	bl FUN_080d99d4
	str r0, [r4]
	ldrh r2, [r5]
	movs r1, #1
	bl FUN_080d99d4
	str r0, [r4]
	ldrh r2, [r5]
	movs r1, #2
	bl FUN_080d99d4
	str r0, [r4]
	add r3, sp, #0x20
	adds r0, r7, #0
	movs r1, #0
	add r2, sp, #0x1c
	bl FUN_080e5610
	mov r1, r8
	cmp r1, #0
	bne _080E5808
	movs r1, #0x80
	lsls r1, r1, #8
	movs r2, #0xbe
	lsls r2, r2, #1
	adds r0, r5, r2
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E5808
	movs r3, #3
	mov r8, r3
_080E5808:
	mov r1, sb
	adds r1, #8
	mov r4, sb
	ldrh r2, [r4]
	ldr r3, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	str r0, [sp]
	str r7, [sp, #4]
	str r5, [sp, #8]
	str r4, [sp, #0xc]
	mov r0, r8
	bl FUN_080d9b3c
	ldr r2, _080E5868 @ =0x00000454
	adds r1, r5, r2
	str r0, [r1]
	movs r3, #0x90
	lsls r3, r3, #3
	adds r0, r5, r3
	ldrb r3, [r0]
	adds r0, r6, #0
	mov r1, r8
	adds r2, r7, #0
	bl FUN_080e5388
	mov r4, r8
	cmp r4, #0
	beq _080E5842
	b _080E59B0
_080E5842:
	movs r7, #8
	ldrsh r0, [r5, r7]
	movs r2, #0xc
	ldrsh r1, [r5, r2]
	movs r3, #0xff
	lsls r3, r3, #1
	adds r2, r5, r3
	movs r4, #0
	ldrsh r2, [r2, r4]
	movs r3, #1
	str r3, [sp]
	mov r7, sb
	ldrh r3, [r7]
	str r3, [sp, #4]
	movs r3, #0
	bl FUN_08240cf0
	b _080E59B0
	.align 2, 0
_080E5868: .4byte 0x00000454
_080E586C:
	movs r1, #2
	movs r2, #0xc0
	lsls r2, r2, #1
	adds r0, r5, r2
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080E587E
	b _080E59B0
_080E587E:
	ldr r3, _080E5914 @ =0x00000454
	adds r6, r5, r3
	ldr r0, [r6]
	ldrh r2, [r5]
	movs r1, #0
	bl FUN_080d99d4
	str r0, [r6]
	ldrh r2, [r5]
	movs r1, #1
	bl FUN_080d99d4
	str r0, [r6]
	ldrh r2, [r5]
	movs r1, #2
	bl FUN_080d99d4
	str r0, [r6]
	bl FUN_080da8a0
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _080E58AE
	b _080E59B0
_080E58AE:
	add r3, sp, #0x20
	adds r0, r7, #0
	movs r1, #1
	add r2, sp, #0x1c
	bl FUN_080e5610
	movs r1, #0x80
	lsls r1, r1, #2
	movs r4, #0xbe
	lsls r4, r4, #1
	adds r0, r5, r4
	ldr r4, [r0]
	ands r4, r1
	rsbs r4, r4, #0
	lsrs r4, r4, #0x1f
	mov sb, r4
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	ldr r3, [sp, #0x1c]
	ldr r0, [sp, #0x20]
	str r0, [sp]
	str r7, [sp, #4]
	movs r4, #0xc9
	lsls r4, r4, #1
	adds r0, r5, r4
	str r0, [sp, #8]
	subs r4, #2
	adds r0, r5, r4
	movs r4, #0
	ldrsh r0, [r0, r4]
	str r0, [sp, #0xc]
	mov r0, sb
	str r0, [sp, #0x10]
	str r5, [sp, #0x14]
	str r5, [sp, #0x18]
	mov r0, r8
	bl FUN_080d9cec
	str r0, [r6]
	movs r1, #0x90
	lsls r1, r1, #3
	adds r0, r5, r1
	ldrb r3, [r0]
	movs r0, #1
	mov r1, r8
	adds r2, r7, #0
	bl FUN_080e5388
	b _080E59B0
	.align 2, 0
_080E5914: .4byte 0x00000454
_080E5918:
	add r3, sp, #0x20
	adds r0, r7, #0
	movs r1, #2
	add r2, sp, #0x1c
	bl FUN_080e5610
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	ldr r3, [sp, #0x20]
	str r7, [sp]
	str r5, [sp, #4]
	movs r0, #1
	bl FUN_080d9f5c
	ldr r2, _080E5940 @ =0x00000454
	adds r1, r5, r2
	str r0, [r1]
	b _080E59B0
	.align 2, 0
_080E5940: .4byte 0x00000454
_080E5944:
	ldr r3, _080E59C0 @ =0x00000454
	adds r6, r5, r3
	ldr r0, [r6]
	ldrh r2, [r5]
	movs r1, #0
	bl FUN_080d99d4
	str r0, [r6]
	ldrh r2, [r5]
	movs r1, #1
	bl FUN_080d99d4
	str r0, [r6]
	ldrh r2, [r5]
	movs r1, #2
	bl FUN_080d99d4
	str r0, [r6]
	ldrh r2, [r5]
	movs r1, #3
	bl FUN_080d9a9c
	str r0, [r6]
	add r3, sp, #0x20
	adds r0, r7, #0
	movs r1, #3
	add r2, sp, #0x1c
	bl FUN_080e5610
	mov r4, r8
	cmp r4, #0
	bne _080E5986
	movs r4, #3
_080E5986:
	adds r1, r5, #0
	adds r1, #8
	ldrh r2, [r5]
	ldr r3, [sp, #0x20]
	str r7, [sp]
	movs r7, #0xc9
	lsls r7, r7, #1
	adds r0, r5, r7
	str r0, [sp, #4]
	subs r7, #2
	adds r0, r5, r7
	movs r7, #0
	ldrsh r0, [r0, r7]
	str r0, [sp, #8]
	str r4, [sp, #0xc]
	str r5, [sp, #0x10]
	str r5, [sp, #0x14]
	movs r0, #7
	bl FUN_080da6c4
	str r0, [r6]
_080E59B0:
	add sp, #0x24
	pop {r3, r4}
	mov r8, r3
	mov sb, r4
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_080E59C0: .4byte 0x00000454

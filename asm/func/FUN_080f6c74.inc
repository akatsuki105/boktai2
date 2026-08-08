	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	movs r1, #0x80
	lsls r1, r1, #0x14
	movs r0, #0xbe
	lsls r0, r0, #1
	adds r6, r4, r0
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	bne _080F6C90
	b _080F6E28
_080F6C90:
	ldr r5, _080F6CCC @ =0x00008006
	movs r1, #0xc0
	lsls r1, r1, #1
	adds r0, r4, r1
	ldrh r2, [r0]
	ands r5, r2
	mov r8, r0
	cmp r5, #0
	beq _080F6CA4
	b _080F6E28
_080F6CA4:
	movs r0, #0x80
	lsls r0, r0, #6
	ands r2, r0
	cmp r2, #0
	bne _080F6CB0
	b _080F6E28
_080F6CB0:
	ldr r2, _080F6CD0 @ =0x000004BE
	adds r0, r4, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _080F6CBC
	b _080F6E28
_080F6CBC:
	ldr r3, _080F6CD4 @ =0x00000553
	adds r0, r4, r3
	ldrb r0, [r0]
	cmp r0, #0x1d
	bne _080F6CD8
	movs r0, #1
	b _080F6E2A
	.align 2, 0
_080F6CCC: .4byte 0x00008006
_080F6CD0: .4byte 0x000004BE
_080F6CD4: .4byte 0x00000553
_080F6CD8:
	ldr r7, _080F6DA4 @ =0x080F5C0D
	mov ip, r7
	movs r1, #0x1d
	ldr r2, _080F6DA8 @ =0x0000046D
	adds r0, r4, r2
	movs r3, #1
	strb r3, [r0]
	ldr r7, _080F6DAC @ =0x0000046B
	adds r0, r4, r7
	strb r5, [r0]
	adds r2, #0xe6
	adds r0, r4, r2
	strb r1, [r0]
	movs r7, #0xaf
	lsls r7, r7, #3
	adds r0, r4, r7
	mov r1, ip
	str r1, [r0]
	movs r2, #0xe4
	lsls r2, r2, #1
	adds r0, r4, r2
	movs r2, #0
	strh r5, [r0]
	movs r1, #3
	movs r7, #0x8d
	lsls r7, r7, #3
	adds r0, r4, r7
	strb r1, [r0]
	ldr r1, _080F6DB0 @ =0x00000469
	adds r0, r4, r1
	strb r2, [r0]
	adds r7, #2
	adds r0, r4, r7
	strb r2, [r0]
	adds r1, #0x1b
	adds r0, r4, r1
	str r5, [r0]
	ldr r2, _080F6DB4 @ =0x0000046C
	adds r0, r4, r2
	strb r3, [r0]
	adds r0, r4, #0
	bl FUN_080e499c
	movs r0, #0x14
	rsbs r0, r0, #0
	mov r3, r8
	ldrh r1, [r3]
	ands r0, r1
	strh r0, [r3]
	movs r1, #3
	rsbs r1, r1, #0
	ldr r0, [r6]
	ands r0, r1
	str r0, [r6]
	movs r7, #0xc1
	lsls r7, r7, #1
	adds r2, r4, r7
	ldr r0, _080F6DB8 @ =0xFFFFF634
	ldrh r1, [r2]
	ands r0, r1
	strh r0, [r2]
	adds r0, r4, #0
	movs r1, #0
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r4, #0
	movs r1, #1
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r4, #0
	movs r1, #3
	movs r2, #0x7f
	movs r3, #0
	bl FUN_080e5718
	adds r0, r4, #0
	movs r1, #4
	bl FUN_080e64b4
	ldr r1, _080F6DBC @ =0x00000464
	adds r0, r4, r1
	strh r5, [r0]
	movs r2, #0x8c
	lsls r2, r2, #3
	adds r0, r4, r2
	strh r5, [r0]
	ldr r3, _080F6DC0 @ =0x00000462
	adds r0, r4, r3
	strh r5, [r0]
	movs r1, #0x40
	ldr r7, _080F6DC4 @ =0x00000474
	adds r0, r4, r7
	ldrh r0, [r0]
	ands r0, r1
	cmp r0, #0
	beq _080F6DC8
	movs r0, #1
	b _080F6DCA
	.align 2, 0
_080F6DA4: .4byte 0x080F5C0D
_080F6DA8: .4byte 0x0000046D
_080F6DAC: .4byte 0x0000046B
_080F6DB0: .4byte 0x00000469
_080F6DB4: .4byte 0x0000046C
_080F6DB8: .4byte 0xFFFFF634
_080F6DBC: .4byte 0x00000464
_080F6DC0: .4byte 0x00000462
_080F6DC4: .4byte 0x00000474
_080F6DC8:
	movs r0, #0
_080F6DCA:
	cmp r0, #0
	beq _080F6DE0
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _080F6DDC @ =0x0000FEFF
	ands r0, r1
	b _080F6E22
	.align 2, 0
_080F6DDC: .4byte 0x0000FEFF
_080F6DE0:
	ldr r1, _080F6E08 @ =0x0000049C
	adds r0, r4, r1
	ldr r0, [r0]
	movs r1, #0x84
	lsls r1, r1, #0xc
	ands r0, r1
	cmp r0, #0
	bne _080F6DFC
	ldr r1, _080F6E0C @ =0x00002016
	mov r2, r8
	ldrh r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _080F6E14
_080F6DFC:
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r1, [r2]
	ldr r0, _080F6E10 @ =0x0000FEFF
	ands r0, r1
	b _080F6E22
	.align 2, 0
_080F6E08: .4byte 0x0000049C
_080F6E0C: .4byte 0x00002016
_080F6E10: .4byte 0x0000FEFF
_080F6E14:
	adds r2, r4, #0
	adds r2, #0xde
	ldrh r1, [r2]
	movs r3, #0x80
	lsls r3, r3, #1
	adds r0, r3, #0
	orrs r0, r1
_080F6E22:
	strh r0, [r2]
	movs r0, #1
	b _080F6E2A
_080F6E28:
	movs r0, #0
_080F6E2A:
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #8
	mov ip, r0
	ldrb r0, [r0, #8]
	subs r6, r0, #1
	cmp r6, #0
	bge _08245F44
	movs r6, #8
_08245F44:
	movs r7, #0
	ldr r0, _08245F78 @ =0x085B0A08
	mov sl, r0
	movs r1, #0xff
	mov sb, r1
	mov r8, sp
	movs r3, #0xa0
	lsls r3, r3, #1
	add r3, ip
_08245F56:
	lsls r0, r7, #1
	mov r2, ip
	ldrh r2, [r2, #6]
	cmp r0, r2
	ble _08245F7C
	lsls r0, r6, #3
	add r0, ip
	ldr r1, [r0, #0x20]
	ldr r0, [r0, #0x1c]
	str r0, [r3]
	str r1, [r3, #4]
	subs r6, #1
	cmp r6, #0
	bge _08245FEE
	movs r6, #8
	b _08245FEE
	.align 2, 0
_08245F78: .4byte 0x085B0A08
_08245F7C:
	mov r1, ip
	adds r1, #0x70
	adds r1, r1, r7
	mov r0, ip
	adds r0, #0x79
	adds r0, r0, r7
	mov r4, sp
	ldrb r2, [r1]
	ldrb r5, [r0]
	adds r0, r2, #0
	adds r0, #0x40
	mov r1, sb
	ands r0, r1
	lsls r0, r0, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08245FA8
	asrs r1, r0, #0xc
	b _08245FAE
_08245FA8:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r1, r0, #0
_08245FAE:
	movs r0, #0
	strh r1, [r4]
	strh r0, [r4, #2]
	mov r0, sb
	ands r2, r0
	lsls r0, r2, #1
	add r0, sl
	movs r1, #0
	ldrsh r0, [r0, r1]
	muls r0, r5, r0
	cmp r0, #0
	blt _08245FCA
	asrs r0, r0, #0xc
	b _08245FD0
_08245FCA:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08245FD0:
	strh r0, [r4, #4]
	mov r2, r8
	ldrh r0, [r2]
	ldrh r1, [r3]
	adds r0, r0, r1
	strh r0, [r3]
	ldrh r0, [r2, #2]
	ldrh r2, [r3, #2]
	adds r0, r0, r2
	strh r0, [r3, #2]
	mov r1, r8
	ldrh r0, [r1, #4]
	ldrh r2, [r3, #4]
	adds r0, r0, r2
	strh r0, [r3, #4]
_08245FEE:
	adds r7, #1
	adds r3, #0x2c
	cmp r7, #8
	ble _08245F56
	mov r1, ip
	ldrh r0, [r1, #6]
	movs r3, #1
	ands r3, r0
	cmp r3, #0
	bne _08246028
	ldrb r2, [r1, #8]
	lsls r2, r2, #3
	add r2, ip
	movs r0, #0xa0
	lsls r0, r0, #1
	add r0, ip
	ldr r1, [r0, #4]
	ldr r0, [r0]
	str r0, [r2, #0x1c]
	str r1, [r2, #0x20]
	mov r2, ip
	ldrb r0, [r2, #8]
	adds r0, #1
	strb r0, [r2, #8]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #8
	bls _08246028
	strb r3, [r2, #8]
_08246028:
	add sp, #8
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

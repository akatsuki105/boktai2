	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	sub sp, #4
	adds r5, r2, #0
	mov r8, r3
	ldr r3, [r0, #8]
	ldrh r4, [r3]
	ldr r2, _08234EE8 @ =0xFFFF0000
	adds r0, r2, #0
	ands r0, r6
	adds r6, r0, #0
	orrs r6, r4
	ldrh r0, [r3, #2]
	ands r2, r7
	adds r7, r2, #0
	orrs r7, r0
	lsls r0, r6, #0x10
	asrs r0, r0, #0x10
	movs r3, #0
	ldrsh r2, [r1, r3]
	subs r2, r0, r2
	lsls r0, r7, #0x10
	asrs r0, r0, #0x10
	movs r3, #4
	ldrsh r1, [r1, r3]
	subs r4, r0, r1
	adds r0, r2, #0
	adds r1, r4, #0
	str r2, [sp]
	bl FUN_0823785c
	lsls r0, r0, #0x18
	lsrs r3, r0, #0x18
	mov r0, r8
	strb r3, [r0]
	ldr r2, [sp]
	adds r1, r2, #0
	cmp r2, #0
	bge _08234ECA
	rsbs r1, r2, #0
_08234ECA:
	ldr r0, [sp, #0x1c]
	cmp r1, r0
	bhi _08234EEC
	adds r1, r4, #0
	cmp r4, #0
	bge _08234ED8
	rsbs r1, r4, #0
_08234ED8:
	ldr r0, [sp, #0x20]
	cmp r1, r0
	bhi _08234EEC
	strh r2, [r5]
	strh r4, [r5, #4]
	movs r0, #1
	b _08234F36
	.align 2, 0
_08234EE8: .4byte 0xFFFF0000
_08234EEC:
	ldr r2, _08234F0C @ =0x085B0A08
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r1, #0
	ldrsh r0, [r0, r1]
	ldr r1, [sp, #0x24]
	muls r0, r1, r0
	cmp r0, #0
	blt _08234F10
	asrs r0, r0, #0xc
	b _08234F16
	.align 2, 0
_08234F0C: .4byte 0x085B0A08
_08234F10:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08234F16:
	strh r0, [r5]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r0, [r0, r2]
	ldr r3, [sp, #0x24]
	muls r0, r3, r0
	cmp r0, #0
	blt _08234F2C
	asrs r0, r0, #0xc
	b _08234F32
_08234F2C:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_08234F32:
	strh r0, [r5, #4]
	movs r0, #0
_08234F36:
	add sp, #4
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

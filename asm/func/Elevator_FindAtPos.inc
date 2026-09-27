	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #0xc
	mov ip, r0
	ldr r0, _081D2254 @ =0x03000194
	ldr r0, [r0]
	mov sb, r0
	cmp r0, #0
	beq _081D22FE
	ldr r1, _081D2258 @ =0x000012AC
	add r1, sb
	ldr r0, [r1]
	cmp r0, #0
	bne _081D2264
	b _081D22FE
	.align 2, 0
_081D2254: .4byte 0x03000194
_081D2258: .4byte 0x000012AC
_081D225C:
	mov r0, r8
	adds r0, #0x1c
	add r0, sb
	b _081D2300
_081D2264:
	movs r7, #0
	mov sl, r1
	mov r6, sp
	movs r0, #0
	mov r8, r0
_081D226E:
	movs r1, #1
	lsls r1, r7
	mov r2, sl
	ldr r0, [r2]
	ands r0, r1
	cmp r0, #0
	beq _081D2280
	movs r0, #1
	b _081D2282
_081D2280:
	movs r0, #0
_081D2282:
	cmp r0, #0
	beq _081D22F2
	mov r3, sp
	mov r2, r8
	add r2, sb
	movs r4, #0x8c
	lsls r4, r4, #1
	adds r2, r2, r4
	mov r5, ip
	ldrh r0, [r5]
	ldrh r1, [r2]
	subs r0, r0, r1
	strh r0, [r6]
	ldrh r1, [r5, #2]
	ldrh r0, [r2, #2]
	subs r4, r1, r0
	strh r4, [r3, #2]
	ldrh r1, [r5, #4]
	ldrh r0, [r2, #4]
	subs r1, r1, r0
	str r1, [sp, #8]
	strh r1, [r3, #4]
	ldr r2, _081D2310 @ =0x085AE0D0
	movs r0, #0
	ldrsh r1, [r6, r0]
	movs r5, #0
	ldrsh r0, [r2, r5]
	cmp r1, r0
	bgt _081D22F2
	cmn r1, r0
	blt _081D22F2
	lsls r0, r4, #0x10
	asrs r0, r0, #0x10
	movs r4, #2
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D22F2
	movs r5, #2
	ldrsh r1, [r3, r5]
	movs r4, #2
	ldrsh r0, [r2, r4]
	cmn r1, r0
	blt _081D22F2
	ldr r5, [sp, #8]
	lsls r0, r5, #0x10
	asrs r0, r0, #0x10
	movs r4, #4
	ldrsh r1, [r2, r4]
	cmp r0, r1
	bgt _081D22F2
	movs r5, #4
	ldrsh r1, [r3, r5]
	movs r3, #4
	ldrsh r0, [r2, r3]
	cmn r1, r0
	bge _081D225C
_081D22F2:
	movs r4, #0xc6
	lsls r4, r4, #1
	add r8, r4
	adds r7, #1
	cmp r7, #0xb
	ble _081D226E
_081D22FE:
	movs r0, #0
_081D2300:
	add sp, #0xc
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081D2310: .4byte 0x085AE0D0

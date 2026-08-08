	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	sub sp, #4
	adds r7, r0, #0
	movs r0, #0
	mov r8, r0
	movs r1, #0xd0
	adds r1, r1, r7
	mov sb, r1
	adds r0, r7, #0
	adds r0, #0x1c
	str r0, [sp]
	adds r3, r0, #0
	mov ip, sb
	movs r1, #0
	mov sl, r1
_08229166:
	movs r6, #0
	mov r1, ip
	ldr r0, [r1]
	cmp r6, r0
	bge _082291AC
	ldr r0, _08229198 @ =0x030046A0
	ldr r0, [r0]
	movs r1, #0x92
	lsls r1, r1, #2
	adds r0, r0, r1
	ldr r5, [r0]
	mov r0, sb
	add r0, sl
	movs r1, #0xd8
	mov r2, r8
	muls r2, r1, r2
	adds r4, r7, #0
	adds r4, #0xd4
	ldr r1, [r0]
_0822918C:
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r5, r0
	bne _0822919C
	movs r0, #1
	b _0822919E
	.align 2, 0
_08229198: .4byte 0x030046A0
_0822919C:
	movs r0, #0
_0822919E:
	cmp r0, #0
	beq _082291A4
	movs r6, #1
_082291A4:
	adds r2, #4
	subs r1, #1
	cmp r1, #0
	bne _0822918C
_082291AC:
	cmp r6, #0
	beq _082291BA
	ldr r0, [r3]
	movs r1, #2
	rsbs r1, r1, #0
	ands r0, r1
	b _082291C0
_082291BA:
	ldr r0, [r3]
	movs r1, #1
	orrs r0, r1
_082291C0:
	str r0, [r3]
	adds r3, #0xd8
	movs r0, #0xd8
	add ip, r0
	add sl, r0
	movs r1, #1
	add r8, r1
	mov r0, r8
	cmp r0, #0xf
	ble _08229166
	movs r1, #0
	mov r8, r1
_082291D8:
	movs r0, #0xd8
	mov r2, r8
	muls r2, r0, r2
	adds r3, r7, r2
	adds r0, r3, #0
	adds r0, #0xc9
	ldrb r1, [r0]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0822921E
	ldr r1, [sp]
	adds r0, r1, r2
	ldr r0, [r0]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _0822921E
	adds r1, r3, #0
	adds r1, #0xe7
	ldrb r0, [r1]
	cmp r0, #0
	beq _0822920A
	subs r0, #1
	strb r0, [r1]
_0822920A:
	adds r0, r7, #0
	adds r0, #0xc4
	adds r0, r0, r2
	adds r1, r2, #0
	adds r1, #0x1c
	adds r1, r7, r1
	ldr r2, [r0]
	adds r0, r7, #0
	bl _call_via_r2
_0822921E:
	movs r0, #1
	add r8, r0
	mov r1, r8
	cmp r1, #0xf
	ble _082291D8
	add sp, #4
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0

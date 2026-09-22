	push {r4, r5, r6, r7, lr}
	mov r7, sl
	mov r6, sb
	mov r5, r8
	push {r5, r6, r7}
	adds r5, r0, #0
	adds r4, r1, #0
	mov sb, r3
	lsls r3, r4, #1
	ldr r1, _08018A60 @ =0x030042B0
	adds r6, r3, r1
	mov ip, r6
	subs r1, #0x20
	adds r7, r3, r1
	mov r1, sb
	cmp r1, #0x1f
	ble _08018A64
	adds r6, r4, #0
	cmp r6, r2
	bge _08018ACE
	subs r6, r2, r6
_08018A4A:
	mov r2, ip
	ldrh r1, [r2]
	strh r1, [r7]
	movs r3, #2
	add ip, r3
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _08018A4A
	b _08018ACE
	.align 2, 0
_08018A60: .4byte 0x030042B0
_08018A64:
	adds r1, r3, #0
	adds r1, #0x28
	adds r5, r5, r1
	mov r8, r5
	movs r1, #0x20
	mov r6, sb
	subs r6, r1, r6
	mov sl, r6
	adds r6, r4, #0
	cmp r6, r2
	bge _08018ACE
	subs r6, r2, r6
_08018A7C:
	mov r2, r8
	ldrh r1, [r2]
	ldr r4, _08018ADC @ =0x00007C1F
	ands r4, r1
	movs r5, #0xf8
	lsls r5, r5, #2
	ands r5, r1
	mov r3, ip
	ldrh r2, [r3]
	adds r1, r2, #0
	ldr r3, _08018ADC @ =0x00007C1F
	ands r1, r3
	mov r3, sb
	muls r3, r1, r3
	mov r1, sl
	muls r1, r4, r1
	adds r3, r3, r1
	ldr r1, _08018AE0 @ =0x000F83E0
	ands r3, r1
	movs r1, #0xf8
	lsls r1, r1, #2
	ands r2, r1
	mov r1, sb
	muls r1, r2, r1
	adds r2, r1, #0
	mov r1, sl
	muls r1, r5, r1
	adds r2, r2, r1
	movs r1, #0xf8
	lsls r1, r1, #7
	ands r2, r1
	orrs r3, r2
	lsrs r3, r3, #5
	strh r3, [r7]
	movs r2, #2
	add r8, r2
	add ip, r2
	adds r7, #2
	subs r6, #1
	cmp r6, #0
	bne _08018A7C
_08018ACE:
	pop {r3, r4, r5}
	mov r8, r3
	mov sb, r4
	mov sl, r5
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_08018ADC: .4byte 0x00007C1F
_08018AE0: .4byte 0x000F83E0

	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	ldr r0, _081EEE20 @ =0x085AE4EC
	mov r8, r0
	adds r5, r6, #0
	adds r5, #0x38
	adds r4, r6, #0
	adds r4, #0x74
	movs r7, #0x7f
_081EEDF2:
	ldrb r0, [r4, #3]
	cmp r0, #1
	bne _081EEE08
	ldrb r0, [r4]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r5, #0
	bl _call_via_r2
_081EEE08:
	adds r5, #0x40
	adds r4, #0x40
	subs r7, #1
	cmp r7, #0
	bge _081EEDF2
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081EEE20: .4byte 0x085AE4EC

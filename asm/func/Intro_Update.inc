	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x44]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08213694
	ldr r0, [r2, #0x60]
	adds r0, #1
	str r0, [r2, #0x60]
_08213694:
	ldr r0, [r2, #0x44]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _082136A4
	ldr r0, [r2, #0x68]
	adds r0, #1
	str r0, [r2, #0x68]
_082136A4:
	movs r1, #0x85
	lsls r1, r1, #3
	adds r0, r2, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

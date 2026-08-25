	push {lr}
	adds r2, r0, #0
	ldr r0, [r2, #0x40]
	movs r1, #1
	ands r0, r1
	cmp r0, #0
	bne _08222A9C
	ldr r0, [r2, #0x4c]
	adds r0, #1
	str r0, [r2, #0x4c]
_08222A9C:
	ldr r0, [r2, #0x40]
	movs r1, #2
	ands r0, r1
	cmp r0, #0
	bne _08222AAC
	ldr r0, [r2, #0x54]
	adds r0, #1
	str r0, [r2, #0x54]
_08222AAC:
	movs r1, #0xdf
	lsls r1, r1, #2
	adds r0, r2, r1
	ldr r1, [r0]
	adds r0, r2, #0
	bl _call_via_r1
	movs r0, #0
	pop {r1}
	bx r1

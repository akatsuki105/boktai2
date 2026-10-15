	push {r4, r5, r6, r7, lr}
	sub sp, #4
	adds r5, r0, #0
	movs r6, #0
	movs r2, #1
	ldr r0, _081F515C @ =0x0000018F
	adds r7, r5, r0
	adds r4, r5, #0
	adds r4, #0x20
_081F514A:
	adds r1, r2, #0
	lsls r1, r6
	ldr r0, [r5, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F5160
	movs r0, #1
	b _081F5162
	.align 2, 0
_081F515C: .4byte 0x0000018F
_081F5160:
	movs r0, #0
_081F5162:
	cmp r0, #0
	bne _081F5184
	adds r0, r4, #0
	movs r1, #0xc2
	lsls r1, r1, #1
	str r2, [sp]
	bl ClearMemory
	ldr r2, [sp]
	adds r1, r2, #0
	lsls r1, r6
	ldr r0, [r5, #0x1c]
	orrs r0, r1
	str r0, [r5, #0x1c]
	strb r6, [r7]
	adds r0, r4, #0
	b _081F5194
_081F5184:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r7, r7, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #7
	ble _081F514A
	movs r0, #0
_081F5194:
	add sp, #4
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

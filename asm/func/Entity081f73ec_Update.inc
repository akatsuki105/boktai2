	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r7, r6, #0
	adds r7, #0x3c
	movs r5, #0
	ldr r0, _081F7348 @ =0x085AE588
	mov r8, r0
_081F7336:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F734C
	movs r0, #1
	b _081F734E
	.align 2, 0
_081F7348: .4byte 0x085AE588
_081F734C:
	movs r0, #0
_081F734E:
	cmp r0, #0
	beq _081F7374
	ldr r0, _081F7388 @ =0x000006EC
	adds r4, r5, #0
	muls r4, r0, r4
	adds r4, r4, r7
	ldr r1, _081F738C @ =0x000006E6
	adds r0, r4, r1
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
	adds r0, r4, #0
	bl FUN_081f6170
_081F7374:
	adds r5, #1
	cmp r5, #0
	ble _081F7336
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_081F7388: .4byte 0x000006EC
_081F738C: .4byte 0x000006E6

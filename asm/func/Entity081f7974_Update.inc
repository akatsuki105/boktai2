	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r4, r0, #0
	adds r1, r4, #0
	adds r1, #0x3c
	ldr r0, [r4, #0x38]
	cmp r0, #0
	beq _081F7900
	movs r7, #0
	ldr r0, _081F78DC @ =0x085AE5A4
	mov r8, r0
	adds r6, r4, #0
	adds r6, #0x82
	adds r5, r1, #0
_081F78CA:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r4, #0x38]
	ands r0, r1
	cmp r0, #0
	beq _081F78E0
	movs r0, #1
	b _081F78E2
	.align 2, 0
_081F78DC: .4byte 0x085AE5A4
_081F78E0:
	movs r0, #0
_081F78E2:
	cmp r0, #0
	beq _081F78F6
	ldrb r0, [r6]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl _call_via_r2
_081F78F6:
	adds r6, #0x48
	adds r5, #0x48
	adds r7, #1
	cmp r7, #0xf
	ble _081F78CA
_081F7900:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

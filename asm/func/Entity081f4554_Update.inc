	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	adds r3, r6, #0
	adds r3, #0x20
	ldr r0, [r6, #0x1c]
	cmp r0, #0
	beq _081F44B8
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F4484 @ =0x030047A4
	ldr r1, _081F4488 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081F44B8
	movs r1, #4
	ldr r0, _081F448C @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081F44B8
	movs r7, #0
	ldr r0, _081F4490 @ =0x085AE560
	mov r8, r0
	movs r0, #0xb9
	lsls r0, r0, #1
	adds r5, r6, r0
	adds r4, r3, #0
_081F4474:
	movs r1, #1
	lsls r1, r7
	ldr r0, [r6, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F4494
	movs r0, #1
	b _081F4496
	.align 2, 0
_081F4484: .4byte 0x030047A4
_081F4488: .4byte 0x030047A0
_081F448C: .4byte 0x03002BC0
_081F4490: .4byte 0x085AE560
_081F4494:
	movs r0, #0
_081F4496:
	cmp r0, #0
	beq _081F44AA
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	bl _call_via_r2
_081F44AA:
	movs r0, #0xba
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r7, #1
	cmp r7, #3
	ble _081F4474
_081F44B8:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

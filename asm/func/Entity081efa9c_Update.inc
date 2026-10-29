	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r5, r0, #0
	adds r7, r5, #0
	adds r7, #0x18
	ldr r1, _081EF9F4 @ =0x00000838
	adds r0, r5, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EFA2E
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081EF9F8 @ =0x030047A4
	ldr r1, _081EF9FC @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081EFA2E
	movs r1, #4
	ldr r0, _081EFA00 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081EFA2E
	movs r4, #0
	ldr r0, _081EF9F4 @ =0x00000838
	adds r6, r5, r0
	ldr r1, _081EFA04 @ =0x085AE4F8
	mov r8, r1
_081EF9E4:
	movs r1, #1
	lsls r1, r4
	ldr r0, [r6]
	ands r0, r1
	cmp r0, #0
	beq _081EFA08
	movs r0, #1
	b _081EFA0A
	.align 2, 0
_081EF9F4: .4byte 0x00000838
_081EF9F8: .4byte 0x030047A4
_081EF9FC: .4byte 0x030047A0
_081EFA00: .4byte 0x03002BC0
_081EFA04: .4byte 0x085AE4F8
_081EFA08:
	movs r0, #0
_081EFA0A:
	cmp r0, #0
	beq _081EFA28
	movs r0, #0xd0
	adds r1, r4, #0
	muls r1, r0, r1
	adds r1, r1, r7
	adds r0, r1, #0
	adds r0, #0xbc
	ldrb r0, [r0]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r5, #0
	bl _call_via_r2
_081EFA28:
	adds r4, #1
	cmp r4, #9
	ble _081EF9E4
_081EFA2E:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0

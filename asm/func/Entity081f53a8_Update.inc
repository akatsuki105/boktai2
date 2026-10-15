	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r7, r0, #0
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081F52EC @ =0x030047A4
	ldr r1, _081F52F0 @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081F5320
	movs r1, #4
	ldr r0, _081F52F4 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081F5320
	movs r6, #0
	ldr r0, _081F52F8 @ =0x085AE578
	mov r8, r0
	movs r0, #0xc7
	lsls r0, r0, #1
	adds r5, r7, r0
	adds r4, r7, #0
	adds r4, #0x20
_081F52DC:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7, #0x1c]
	ands r0, r1
	cmp r0, #0
	beq _081F52FC
	movs r0, #1
	b _081F52FE
	.align 2, 0
_081F52EC: .4byte 0x030047A4
_081F52F0: .4byte 0x030047A0
_081F52F4: .4byte 0x03002BC0
_081F52F8: .4byte 0x085AE578
_081F52FC:
	movs r0, #0
_081F52FE:
	cmp r0, #0
	beq _081F5312
	ldrb r0, [r5]
	lsls r0, r0, #2
	add r0, r8
	ldr r2, [r0]
	adds r0, r7, #0
	adds r1, r4, #0
	bl _call_via_r2
_081F5312:
	movs r0, #0xc2
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #7
	ble _081F52DC
_081F5320:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

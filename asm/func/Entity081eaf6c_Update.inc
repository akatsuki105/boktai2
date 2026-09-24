	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r3, r0, #0
	adds r4, r3, #0
	adds r4, #0x3c
	ldr r1, _081EAB34 @ =0x0000052C
	adds r0, r3, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _081EAB6C
	movs r2, #0x80
	lsls r2, r2, #3
	ldr r0, _081EAB38 @ =0x030047A4
	ldr r1, _081EAB3C @ =0x030047A0
	ldr r0, [r0]
	ldr r1, [r1]
	orrs r0, r1
	ands r0, r2
	cmp r0, #0
	bne _081EAB6C
	movs r1, #4
	ldr r0, _081EAB40 @ =0x03002BC0
	ldr r0, [r0]
	ands r0, r1
	cmp r0, #0
	bne _081EAB6C
	movs r6, #0
	ldr r0, _081EAB34 @ =0x0000052C
	adds r7, r3, r0
	ldr r1, _081EAB44 @ =0x085AE48C
	mov r8, r1
	movs r0, #0xb7
	lsls r0, r0, #1
	adds r5, r3, r0
_081EAB22:
	movs r1, #1
	lsls r1, r6
	ldr r0, [r7]
	ands r0, r1
	cmp r0, #0
	beq _081EAB48
	movs r0, #1
	b _081EAB4A
	.align 2, 0
_081EAB34: .4byte 0x0000052C
_081EAB38: .4byte 0x030047A4
_081EAB3C: .4byte 0x030047A0
_081EAB40: .4byte 0x03002BC0
_081EAB44: .4byte 0x085AE48C
_081EAB48:
	movs r0, #0
_081EAB4A:
	cmp r0, #0
	beq _081EAB5E
	movs r1, #0
	ldrsh r0, [r5, r1]
	lsls r0, r0, #2
	add r0, r8
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
_081EAB5E:
	movs r0, #0x9e
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	adds r6, #1
	cmp r6, #3
	ble _081EAB22
_081EAB6C:
	movs r0, #0
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1

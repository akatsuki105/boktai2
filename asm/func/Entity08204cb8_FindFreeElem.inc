	push {r4, lr}
	ldr r0, _08204844 @ =0x03000220
	ldr r1, [r0]
	adds r0, r1, #0
	adds r0, #0x3c
	ldrb r0, [r0]
	cmp r0, #0xf
	bls _0820484C
	b _0820486A
	.align 2, 0
_08204844: .4byte 0x03000220
_08204848:
	adds r0, r1, #0
	b _0820486C
_0820484C:
	adds r1, #0x40
	movs r2, #0
	movs r3, #1
_08204852:
	movs r4, #0x3c
	ldrsh r0, [r1, r4]
	cmp r0, #0
	bgt _08204862
	ldr r0, [r1]
	ands r0, r3
	cmp r0, #0
	bne _08204848
_08204862:
	adds r1, #0x44
	adds r2, #1
	cmp r2, #0xf
	ble _08204852
_0820486A:
	movs r0, #0
_0820486C:
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0

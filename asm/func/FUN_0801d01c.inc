	push {r4, lr}
	adds r3, r0, #0
	movs r4, #1
	movs r0, #0x9c
	lsls r0, r0, #1
	adds r1, r3, r0
	movs r2, #0x12
_0801D02A:
	ldr r0, [r1, #0x2c]
	orrs r0, r4
	str r0, [r1, #0x2c]
	adds r1, #0x84
	subs r2, #1
	cmp r2, #0
	bge _0801D02A
	movs r4, #1
	ldr r0, _0801D078 @ =0x00000B0C
	adds r1, r3, r0
	movs r2, #2
_0801D040:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0801D040
	movs r4, #1
	ldr r0, _0801D07C @ =0x00000C2C
	adds r1, r3, r0
	movs r2, #3
_0801D056:
	ldr r0, [r1]
	orrs r0, r4
	str r0, [r1]
	adds r1, #0x60
	subs r2, #1
	cmp r2, #0
	bge _0801D056
	ldr r1, _0801D080 @ =0x00000DA4
	adds r0, r3, r1
	ldr r1, [r0, #8]
	movs r2, #1
	orrs r1, r2
	str r1, [r0, #8]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_0801D078: .4byte 0x00000B0C
_0801D07C: .4byte 0x00000C2C
_0801D080: .4byte 0x00000DA4

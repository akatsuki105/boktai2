	push {r4, r5, r6, r7, lr}
	adds r6, r0, #0
	adds r4, r6, #0
	adds r4, #0x40
	movs r5, #0
	ldr r7, _0805B71C @ =0x085ABA20
_0805B6EC:
	movs r1, #1
	lsls r1, r5
	ldr r0, [r6, #0x18]
	ands r0, r1
	cmp r0, #0
	beq _0805B70A
	ldrb r0, [r4, #2]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r3, [r0]
	adds r0, r6, #0
	adds r1, r4, #0
	adds r2, r5, #0
	bl _call_via_r3
_0805B70A:
	adds r5, #1
	adds r4, #0x8c
	cmp r5, #0xf
	ble _0805B6EC
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_0805B71C: .4byte 0x085ABA20

	push {r4, r5, r6, r7, lr}
	adds r1, r0, #0
	adds r2, r1, #0
	adds r2, #0x5c
	ldr r3, _080DA730 @ =0x000009FC
	adds r0, r1, r3
	ldr r0, [r0]
	cmp r0, #0
	beq _080DA728
	ldr r7, _080DA734 @ =0x085AD304
	adds r5, r1, #0
	adds r5, #0x89
	adds r4, r2, #0
	ldr r0, _080DA738 @ =0x000008C8
	adds r6, r1, r0
_080DA70E:
	ldrb r0, [r5]
	lsls r0, r0, #2
	adds r0, r0, r7
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	movs r0, #0x9a
	lsls r0, r0, #1
	adds r5, r5, r0
	adds r4, r4, r0
	cmp r4, r6
	ble _080DA70E
_080DA728:
	movs r0, #0
	pop {r4, r5, r6, r7}
	pop {r1}
	bx r1
	.align 2, 0
_080DA730: .4byte 0x000009FC
_080DA734: .4byte 0x085AD304
_080DA738: .4byte 0x000008C8

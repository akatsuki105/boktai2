	push {r4, r5, r6, lr}
	adds r5, r0, #0
	movs r6, #0
	adds r4, r5, #0
	adds r4, #0x6c
_081E180A:
	adds r0, r5, #0
	adds r1, r4, #0
	bl FUN_081e1260
	cmp r0, #0
	bge _081E181C
	movs r0, #1
	rsbs r0, r0, #0
	b _081E182C
_081E181C:
	adds r4, #0x90
	adds r6, #1
	cmp r6, #4
	ble _081E180A
	movs r1, #0
	ldr r0, _081E1834 @ =0x030001B0
	str r1, [r0]
	movs r0, #0
_081E182C:
	pop {r4, r5, r6}
	pop {r1}
	bx r1
	.align 2, 0
_081E1834: .4byte 0x030001B0

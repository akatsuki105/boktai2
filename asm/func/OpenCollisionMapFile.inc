	push {lr}
	adds r2, r0, #0
	ldrb r0, [r2]
	cmp r0, #0x48
	bne _0823B554
	ldrb r0, [r2, #1]
	cmp r0, #0x50
	bne _0823B554
	adds r0, r2, #0
	b _0823B55E
_0823B554:
	ldr r1, _0823B564 @ =0x02031400
	adds r0, r2, #0
	bl LZ77UnCompReadNormalWrite8bit
	ldr r0, _0823B568 @ =0x02031404
_0823B55E:
	pop {r1}
	bx r1
	.align 2, 0
_0823B564: .4byte 0x02031400
_0823B568: .4byte 0x02031404

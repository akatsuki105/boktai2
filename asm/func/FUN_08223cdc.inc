	push {r4, lr}
	adds r4, r0, #0
	movs r0, #0x8f
	lsls r0, r0, #1
	bl PlaySound_082406e0
	ldr r0, _08223CF8 @ =0x00000F54
	adds r4, r4, r0
	ldr r0, _08223CFC @ =FUN_08223d00
	str r0, [r4]
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08223CF8: .4byte 0x00000F54
_08223CFC: .4byte FUN_08223d00

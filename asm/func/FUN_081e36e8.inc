	push {r4, lr}
	adds r4, r0, #0
	bl FUN_081e3680
	ldr r0, _081E370C @ =0x000015E2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	ldr r0, _081E3710 @ =0x000015BC
	adds r4, r4, r0
	adds r0, r4, #0
	movs r1, #0x24
	bl ClearMemory
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_081E370C: .4byte 0x000015E2
_081E3710: .4byte 0x000015BC

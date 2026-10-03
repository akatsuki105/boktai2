	push {r4, r5, r6, lr}
	adds r6, r0, #0
	ldr r0, _08090144 @ =0x00002CA4
	adds r4, r6, r0
	movs r5, #3
_0809012A:
	adds r0, r4, #0
	adds r1, r6, #0
	adds r1, #0x80
	bl MainSprite_AdvanceAnim
	adds r4, #0x60
	subs r5, #1
	cmp r5, #0
	bge _0809012A
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_08090144: .4byte 0x00002CA4

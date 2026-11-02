	push {lr}
	ldr r2, _08003F34 @ =0x085AA650
	adds r1, r1, r2
	ldrb r1, [r1]
	bl EntityD9AE_PushAt
	pop {r1}
	bx r1
	.align 2, 0
_08003F34: .4byte 0x085AA650

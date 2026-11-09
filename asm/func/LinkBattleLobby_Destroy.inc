	push {lr}
	bl LinkBattleLobby_RemoveSprites
	ldr r1, _081DC578 @ =0x030001A8
	movs r0, #0
	str r0, [r1]
	movs r0, #1
	pop {r1}
	bx r1
	.align 2, 0
_081DC578: .4byte 0x030001A8

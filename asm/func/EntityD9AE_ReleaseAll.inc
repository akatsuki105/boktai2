	push {r4, r5, r6, lr}
	ldr r0, _080036F0 @ =0x03000020
	ldr r6, [r0]
	cmp r6, #0
	bne _080036F4
	movs r0, #1
	rsbs r0, r0, #0
	b _08003716
	.align 2, 0
_080036F0: .4byte 0x03000020
_080036F4:
	ldr r4, [r6, #0x70]
	movs r5, #0
	b _0800370E
_080036FA:
	ldrb r0, [r4, #0x1e]
	cmp r0, #0
	beq _08003706
	adds r0, r4, #0
	bl EntityD9AEElem_Release
_08003706:
	movs r0, #0xce
	lsls r0, r0, #1
	adds r4, r4, r0
	adds r5, #1
_0800370E:
	ldrh r0, [r6, #0x18]
	cmp r5, r0
	blt _080036FA
	movs r0, #0
_08003716:
	pop {r4, r5, r6}
	pop {r1}
	bx r1

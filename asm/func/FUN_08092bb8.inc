	push {r4, lr}
	adds r4, r0, #0
	ldr r0, _08092BCC @ =0x000009EE
	adds r1, r4, r0
	ldrh r0, [r1]
	cmp r0, #0xf
	bhi _08092BD0
	adds r0, #1
	strh r0, [r1]
	b _08092BE4
	.align 2, 0
_08092BCC: .4byte 0x000009EE
_08092BD0:
	adds r0, r4, #0
	bl FUN_0808c1cc
	cmp r0, #0
	beq _08092BE4
	ldr r1, _08092BEC @ =FUN_08092bf0
	adds r0, r4, #0
	movs r2, #1
	bl FUN_0808a354
_08092BE4:
	pop {r4}
	pop {r0}
	bx r0
	.align 2, 0
_08092BEC: .4byte FUN_08092bf0

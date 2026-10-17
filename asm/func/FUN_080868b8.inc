	push {r4, r5, lr}
	adds r1, r0, #0
	ldr r0, _080868D4 @ =0x03002C00
	ldr r4, [r0]
	cmp r4, #0
	beq _0808690A
	cmp r1, #0
	beq _080868D8
	adds r0, r4, #0
	movs r1, #7
	bl Coffin_SetState
	b _080868E0
	.align 2, 0
_080868D4: .4byte 0x03002C00
_080868D8:
	adds r0, r4, #0
	movs r1, #6
	bl Coffin_SetState
_080868E0:
	movs r0, #0xfa
	lsls r0, r0, #1
	adds r5, r4, r0
	ldrb r0, [r5]
	cmp r0, #0
	beq _080868FA
	movs r1, #0xf2
	lsls r1, r1, #1
	adds r0, r4, r1
	bl EnemyTargetManager_Remove
	movs r0, #0
	strb r0, [r5]
_080868FA:
	movs r0, #0xc8
	lsls r0, r0, #2
	adds r1, r4, r0
	movs r0, #0
	strh r0, [r1]
	adds r0, r4, #0
	bl FUN_08086080
_0808690A:
	pop {r4, r5}
	pop {r0}
	bx r0

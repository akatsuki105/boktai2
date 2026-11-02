	push {lr}
	adds r1, r0, #0
	ldr r0, _081E0320 @ =0x000003BA
	adds r2, r1, r0
	ldrh r0, [r2]
	cmp r0, #0
	beq _081E031A
	subs r0, #1
	strh r0, [r2]
	lsls r0, r0, #0x10
	cmp r0, #0
	bne _081E031A
	movs r2, #0xef
	lsls r2, r2, #2
	adds r0, r1, r2
	ldrh r2, [r0]
	adds r0, r1, #0
	movs r1, #0
	bl Entity501B_SetNumber
	ldr r0, _081E0324 @ =0x00000167
	bl PlaySound_082406e0
_081E031A:
	pop {r0}
	bx r0
	.align 2, 0
_081E0320: .4byte 0x000003BA
_081E0324: .4byte 0x00000167

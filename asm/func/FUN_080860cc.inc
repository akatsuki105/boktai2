	push {lr}
	adds r2, r0, #0
	ldr r1, _08086100 @ =0x000003A6
	adds r0, r2, r1
	ldrh r1, [r0]
	movs r3, #0xe9
	lsls r3, r3, #2
	adds r0, r2, r3
	strh r1, [r0]
	ldr r1, _08086104 @ =0x000003A2
	adds r0, r2, r1
	ldrh r0, [r0]
	cmp r0, #0
	beq _080860F4
	movs r3, #0xe1
	lsls r3, r3, #2
	adds r0, r2, r3
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808610C
_080860F4:
	ldr r0, _08086108 @ =0x03002C00
	ldr r0, [r0]
	movs r1, #0
	bl Coffin_SetState
	b _08086132
	.align 2, 0
_08086100: .4byte 0x000003A6
_08086104: .4byte 0x000003A2
_08086108: .4byte 0x03002C00
_0808610C:
	adds r0, r2, #0
	bl FUN_0808608c
	cmp r0, #0
	beq _08086128
	ldr r0, _08086124 @ =0x03002C00
	ldr r0, [r0]
	movs r1, #3
	bl Coffin_SetState
	b _08086132
	.align 2, 0
_08086124: .4byte 0x03002C00
_08086128:
	ldr r0, _08086138 @ =0x03002C00
	ldr r0, [r0]
	movs r1, #4
	bl Coffin_SetState
_08086132:
	pop {r0}
	bx r0
	.align 2, 0
_08086138: .4byte 0x03002C00

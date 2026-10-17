	push {r4, r5, r6, r7, lr}
	sub sp, #8
	adds r5, r0, #0
	ldr r1, _08088760 @ =0x000001F5
	adds r0, r5, r1
	ldrb r0, [r0]
	cmp r0, #4
	beq _08088730
	adds r0, r5, #0
	movs r1, #4
	bl Coffin_SetState
_08088730:
	ldr r0, _08088764 @ =0x030047A4
	ldr r1, [r0]
	movs r6, #0x80
	lsls r6, r6, #2
	ands r1, r6
	cmp r1, #0
	beq _08088740
	b _08088902
_08088740:
	movs r2, #0xc9
	lsls r2, r2, #2
	adds r0, r5, r2
	ldrh r7, [r0]
	cmp r7, #0
	beq _0808876C
	ldr r4, _08088768 @ =0x0000032A
	adds r0, r5, r4
	strh r1, [r0]
	adds r2, #0x94
	adds r0, r5, r2
	strh r1, [r0]
	adds r0, r5, #0
	bl FUN_080856f4
	b _08088902
	.align 2, 0
_08088760: .4byte 0x000001F5
_08088764: .4byte 0x030047A4
_08088768: .4byte 0x0000032A
_0808876C:
	ldr r4, _080887B8 @ =0x0000032A
	adds r0, r5, r4
	movs r1, #1
	strh r1, [r0]
	movs r1, #0xee
	lsls r1, r1, #2
	adds r0, r5, r1
	ldrh r0, [r0]
	cmp r0, #0x5a
	bne _08088800
	ldr r2, _080887BC @ =0x000003BA
	adds r4, r5, r2
	ldrh r0, [r4]
	cmp r0, #0
	beq _080887C8
	ldr r2, _080887C0 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	adds r1, #0x47
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r1, _080887C4 @ =0x0203B400
	adds r0, r0, r1
	ldrh r0, [r0]
	movs r1, #5
	bl Mod
	adds r2, r5, r6
	ldrb r1, [r2]
	adds r1, r1, r0
	adds r1, #2
	movs r0, #7
	ands r1, r0
	strb r1, [r2]
	strh r7, [r4]
	b _080888BA
	.align 2, 0
_080887B8: .4byte 0x0000032A
_080887BC: .4byte 0x000003BA
_080887C0: .4byte 0x030046B8
_080887C4: .4byte 0x0203B400
_080887C8:
	ldr r2, _080887F4 @ =0x030046B8
	ldr r0, [r2]
	adds r0, #1
	ldr r1, _080887F8 @ =0x000003FF
	ands r0, r1
	str r0, [r2]
	lsls r0, r0, #1
	ldr r2, _080887FC @ =0x0203B400
	adds r0, r0, r2
	ldrh r0, [r0]
	movs r1, #3
	bl Mod
	adds r2, r5, r6
	ldrb r1, [r2]
	adds r1, r1, r0
	adds r1, #7
	movs r0, #7
	ands r1, r0
	strb r1, [r2]
	b _080888BA
	.align 2, 0
_080887F4: .4byte 0x030046B8
_080887F8: .4byte 0x000003FF
_080887FC: .4byte 0x0203B400
_08088800:
	cmp r0, #0x5a
	bls _080888BA
	adds r0, r5, r6
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r3, r0, #5
	ldr r2, _08088830 @ =gSineTable
	adds r0, r3, #0
	adds r0, #0x40
	movs r1, #0xff
	ands r0, r1
	lsls r0, r0, #1
	adds r0, r0, r2
	movs r4, #0
	ldrsh r1, [r0, r4]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _08088834
	asrs r0, r0, #0xc
	b _0808883A
	.align 2, 0
_08088830: .4byte gSineTable
_08088834:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808883A:
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	str r0, [sp]
	lsls r0, r3, #1
	adds r0, r0, r2
	movs r2, #0
	ldrsh r1, [r0, r2]
	lsls r0, r1, #1
	adds r0, r0, r1
	cmp r0, #0
	blt _08088854
	asrs r0, r0, #0xc
	b _0808885A
_08088854:
	rsbs r0, r0, #0
	asrs r0, r0, #0xc
	rsbs r0, r0, #0
_0808885A:
	lsls r1, r0, #0x10
	lsrs r1, r1, #0x10
	ldr r2, _0808889C @ =0xFFFF0000
	mov r6, sp
	ldr r0, [sp, #4]
	ands r0, r2
	orrs r0, r1
	str r0, [sp, #4]
	adds r4, r5, #0
	adds r4, #0x48
	ldr r2, _080888A0 @ =0x00000843
	adds r0, r4, #0
	mov r1, sp
	bl FUN_08088430
	cmp r0, #0
	beq _080888A8
	mov r0, sp
	ldrh r0, [r0]
	ldrh r1, [r4]
	adds r0, r0, r1
	strh r0, [r4]
	adds r1, r5, #0
	adds r1, #0x4c
	ldrh r0, [r6, #4]
	ldrh r2, [r1]
	adds r0, r0, r2
	strh r0, [r1]
	ldr r4, _080888A4 @ =0x0000033A
	adds r1, r5, r4
	movs r0, #1
	strb r0, [r1]
	b _080888BA
	.align 2, 0
_0808889C: .4byte 0xFFFF0000
_080888A0: .4byte 0x00000843
_080888A4: .4byte 0x0000033A
_080888A8:
	movs r0, #0xee
	lsls r0, r0, #2
	adds r1, r5, r0
	movs r0, #0x1e
	strh r0, [r1]
	ldr r2, _080888D4 @ =0x000003BA
	adds r1, r5, r2
	movs r0, #1
	strh r0, [r1]
_080888BA:
	ldrb r0, [r5, #0x1a]
	cmp r0, #5
	bne _080888DC
	ldr r4, _080888D8 @ =0x0000033A
	adds r0, r5, r4
	ldrb r0, [r0]
	cmp r0, #0
	beq _080888DC
	adds r0, r5, #0
	movs r1, #0x20
	bl FUN_08085ef8
	b _080888E4
	.align 2, 0
_080888D4: .4byte 0x000003BA
_080888D8: .4byte 0x0000033A
_080888DC:
	adds r0, r5, #0
	movs r1, #0
	bl FUN_08086024
_080888E4:
	movs r0, #0xee
	lsls r0, r0, #2
	adds r4, r5, r0
	ldrh r0, [r4]
	adds r0, #1
	strh r0, [r4]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x77
	bls _08088902
	adds r0, r5, #0
	bl FUN_080860cc
	movs r0, #0
	strh r0, [r4]
_08088902:
	add sp, #8
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0

	push {r4, r5, lr}
	sub sp, #0x10
	adds r4, r0, #0
	adds r5, r3, #0
	cmp r1, #8
	bls _080530A6
	b _0805321A
_080530A6:
	lsls r0, r1, #2
	ldr r1, _080530B0 @ =_080530B4
	adds r0, r0, r1
	ldr r0, [r0]
	mov pc, r0
	.align 2, 0
_080530B0: .4byte _080530B4
_080530B4: @ jump table
	.4byte _080530D8 @ case 0
	.4byte _0805311E @ case 1
	.4byte _08053104 @ case 2
	.4byte _08053146 @ case 3
	.4byte _08053170 @ case 4
	.4byte _08053196 @ case 5
	.4byte _080531BC @ case 6
	.4byte _080531D8 @ case 7
	.4byte _080531F4 @ case 8
_080530D8:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #1
	bl Emote_Show
	str r0, [r4, #0x24]
	ldr r0, _08053100 @ =0x000001B1
	bl PlaySound_082406e0
	b _0805321A
	.align 2, 0
_08053100: .4byte 0x000001B1
_08053104:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #0
	b _08053136
_0805311E:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #3
_08053136:
	bl Emote_Show
	str r0, [r4, #0x24]
	movs r0, #0xf6
	lsls r0, r0, #1
	bl PlaySound_082406e0
	b _0805321A
_08053146:
	movs r2, #0
	str r2, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #0
	movs r3, #2
	bl Emote_Show
	str r0, [r4, #0x24]
	ldr r0, _0805316C @ =0x000001ED
	bl PlaySound_082406e0
	b _0805321A
	.align 2, 0
_0805316C: .4byte 0x000001ED
_08053170:
	movs r0, #1
	str r0, [r4, #0x28]
	movs r3, #0
	strh r2, [r4, #0x2c]
	strh r5, [r4, #0x2e]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	adds r2, r4, #0
	adds r2, #0x2c
	str r2, [sp]
	movs r5, #0x2e
	ldrsh r2, [r4, r5]
	str r2, [sp, #4]
	str r3, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #1
	b _08053214
_08053196:
	movs r0, #3
	str r0, [r4, #0x28]
	movs r3, #0
	strh r2, [r4, #0x2c]
	strh r5, [r4, #0x2e]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	adds r2, r4, #0
	adds r2, #0x2c
	str r2, [sp]
	movs r5, #0x2e
	ldrsh r2, [r4, r5]
	str r2, [sp, #4]
	str r3, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #3
	b _08053214
_080531BC:
	movs r0, #5
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #5
	movs r3, #0
	b _08053214
_080531D8:
	movs r0, #4
	str r0, [r4, #0x28]
	ldr r0, [r4, #0x24]
	adds r1, r4, #0
	adds r1, #0x30
	movs r2, #0
	str r2, [sp]
	str r2, [sp, #4]
	str r2, [sp, #8]
	movs r2, #0x64
	str r2, [sp, #0xc]
	movs r2, #4
	movs r3, #0
	b _08053214
_080531F4:
	ldr r3, [r4, #0x24]
	cmp r3, #0
	beq _0805321A
	adds r1, r4, #0
	adds r1, #0x30
	ldr r2, [r4, #0x28]
	lsls r2, r2, #0x18
	lsrs r2, r2, #0x18
	movs r0, #0
	str r0, [sp]
	str r0, [sp, #4]
	str r0, [sp, #8]
	movs r0, #0x64
	str r0, [sp, #0xc]
	adds r0, r3, #0
	movs r3, #0x7f
_08053214:
	bl Emote_Show
	str r0, [r4, #0x24]
_0805321A:
	add sp, #0x10
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

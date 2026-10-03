	push {r4, r5, lr}
	sub sp, #4
	adds r4, r0, #0
	ldr r1, _0808B564 @ =0x00000F56
	adds r0, r4, r1
	ldrb r1, [r0]
	subs r0, r1, #1
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _0808B4DC
	cmp r1, #6
	beq _0808B4DC
	b _0808B5F4
_0808B4DC:
	ldr r2, _0808B568 @ =0x000009F8
	adds r0, r4, r2
	ldrb r0, [r0]
	cmp r0, #0
	beq _0808B524
	ldr r2, _0808B56C @ =0x030044E0
	ldrh r1, [r2]
	movs r0, #4
	ands r0, r1
	cmp r0, #0
	beq _0808B524
	ldrh r1, [r2, #2]
	movs r0, #1
	ands r0, r1
	cmp r0, #0
	beq _0808B524
	ldr r0, _0808B570 @ =0x00003AE6
	adds r1, r4, r0
	ldrb r0, [r1]
	adds r0, #1
	movs r2, #0
	strb r0, [r1]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #2
	bls _0808B512
	strb r2, [r1]
_0808B512:
	ldr r1, _0808B574 @ =0x00003AE7
	adds r0, r4, r1
	strb r2, [r0]
	movs r0, #0xdc
	bl PlaySound_082406e0
	adds r0, r4, #0
	bl FUN_0808b38c
_0808B524:
	movs r0, #0
	movs r1, #0x12
	movs r2, #0
	bl FUN_0808a420
	adds r1, r0, #0
	ldr r2, _0808B570 @ =0x00003AE6
	adds r0, r4, r2
	ldrb r4, [r0]
	cmp r4, #0
	bne _0808B57C
	ldr r2, _0808B578 @ =0x0000F020
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	bl Time_GetHour
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_0808b30c
	bl Time_GetMinute
	b _0808B5A8
	.align 2, 0
_0808B564: .4byte 0x00000F56
_0808B568: .4byte 0x000009F8
_0808B56C: .4byte 0x030044E0
_0808B570: .4byte 0x00003AE6
_0808B574: .4byte 0x00003AE7
_0808B578: .4byte 0x0000F020
_0808B57C:
	cmp r4, #1
	bne _0808B5C0
	ldr r2, _0808B5B8 @ =0x0000F027
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B5BC @ =0x030047E0
	ldrb r0, [r5, #0xa]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_0808b30c
	ldrb r0, [r5, #0xb]
_0808B5A8:
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_0808b30c
	b _0808B5F4
	.align 2, 0
_0808B5B8: .4byte 0x0000F027
_0808B5BC: .4byte 0x030047E0
_0808B5C0:
	ldr r2, _0808B5FC @ =0x0000F027
	adds r0, r2, #0
	strh r0, [r1]
	adds r1, #2
	adds r2, #1
	adds r0, r2, #0
	strh r0, [r1]
	adds r2, #2
	adds r0, r2, #0
	strh r0, [r1, #2]
	ldr r5, _0808B600 @ =0x030047E0
	ldrb r0, [r5, #0xc]
	movs r4, #0
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x16
	movs r3, #0
	bl FUN_0808b30c
	ldrb r0, [r5, #0xd]
	str r4, [sp]
	movs r1, #0xa
	movs r2, #0x19
	movs r3, #0
	bl FUN_0808b30c
_0808B5F4:
	add sp, #4
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_0808B5FC: .4byte 0x0000F027
_0808B600: .4byte 0x030047E0

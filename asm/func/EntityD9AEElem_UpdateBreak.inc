	push {r4, r5, lr}
	sub sp, #0x1c
	adds r4, r0, #0
	ldrb r0, [r4, #0x11]
	cmp r0, #0
	beq _0800422C
	movs r5, #0
	strb r5, [r4, #0x11]
	adds r0, r4, #0
	adds r0, #0x20
	strb r5, [r0]
	adds r0, #0x6c
	strh r5, [r0, #0x10]
	movs r0, #0x9b
	lsls r0, r0, #1
	bl PlaySound_082406e0
	adds r2, r4, #0
	adds r2, #0xbe
	ldrh r1, [r2]
	movs r0, #0x21
	orrs r0, r1
	strh r0, [r2]
	ldr r2, [r4, #0x28]
	cmp r2, #0
	beq _0800422C
	ldrh r0, [r4, #0x2c]
	str r0, [sp]
	ldrb r0, [r4]
	str r0, [sp, #4]
	movs r1, #0x34
	ldrsh r0, [r4, r1]
	str r0, [sp, #8]
	movs r1, #0x36
	ldrsh r0, [r4, r1]
	str r0, [sp, #0xc]
	movs r1, #0x38
	ldrsh r0, [r4, r1]
	str r0, [sp, #0x10]
	ldr r1, _0800425C @ =0xFFFF0000
	ldr r0, [sp, #0x14]
	ands r0, r1
	movs r1, #5
	orrs r0, r1
	str r0, [sp, #0x14]
	add r1, sp, #0x14
	mov r0, sp
	str r0, [r1, #4]
	adds r0, r2, #0
	bl VM_ExecByID
	str r5, [r4, #0x28]
_0800422C:
	adds r2, r4, #0
	adds r2, #0x20
	ldrb r0, [r2]
	adds r5, r2, #0
	cmp r0, #0
	bne _08004280
	ldrh r0, [r4, #2]
	movs r1, #2
	bl Mod
	adds r1, r0, #0
	cmp r1, #0
	bne _08004266
	adds r0, r4, #0
	adds r0, #0x9c
	movs r2, #0
	ldrsh r0, [r0, r2]
	cmp r0, #0
	bne _08004260
	adds r1, r4, #0
	adds r1, #0x8c
	movs r0, #1
	strh r0, [r1, #0x10]
	b _08004266
	.align 2, 0
_0800425C: .4byte 0xFFFF0000
_08004260:
	adds r0, r4, #0
	adds r0, #0x8c
	strh r1, [r0, #0x10]
_08004266:
	ldrh r0, [r4, #2]
	adds r1, r0, #1
	strh r1, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #0x1d
	bls _080042AE
	movs r0, #0
	strh r0, [r4, #2]
	ldrb r0, [r5]
	adds r0, #1
	strb r0, [r5]
	b _080042AE
_08004280:
	ldrh r0, [r4, #2]
	adds r1, r0, #1
	strh r1, [r4, #2]
	lsls r0, r0, #0x10
	lsrs r0, r0, #0x10
	cmp r0, #5
	bls _080042AE
	movs r0, #0
	strh r0, [r4, #2]
	ldrb r0, [r2]
	adds r0, #1
	strb r0, [r2]
	lsls r0, r0, #0x18
	lsrs r0, r0, #0x18
	cmp r0, #3
	bls _080042A6
	movs r0, #2
	strb r0, [r4, #0x19]
	b _080042AE
_080042A6:
	ldrb r1, [r2]
	adds r0, r4, #0
	adds r0, #0x8c
	strh r1, [r0, #0x10]
_080042AE:
	add sp, #0x1c
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

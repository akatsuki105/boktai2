	push {r4, r5, r6, lr}
	adds r4, r0, #0
	adds r5, r4, #0
	adds r5, #0xa8
	ldrh r0, [r5]
	cmp r0, #0
	bne _080A2040
	adds r0, r4, #0
	bl FUN_080a1f5c
	cmp r0, #0
	beq _080A200C
	ldr r0, _080A2034 @ =0x03002C00
	ldr r0, [r0]
	ldr r1, _080A2038 @ =0x000001F5
	adds r0, r0, r1
	ldrb r0, [r0]
	cmp r0, #1
	bne _080A200C
	strh r0, [r5]
	movs r2, #0x98
	lsls r2, r2, #2
	adds r0, r4, r2
	ldr r0, [r0]
	cmp r0, #0
	beq _080A1FFE
	movs r1, #0
	bl VM_ExecByID
_080A1FFE:
	movs r0, #1
	bl FUN_0808670c
	movs r0, #0xcc
	lsls r0, r0, #1
	bl PlaySound_082406e0
_080A200C:
	adds r1, r4, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080A203C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #7
	ands r0, r1
	cmp r0, #0
	bne _080A2090
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_080a1e78
	b _080A2090
	.align 2, 0
_080A2034: .4byte 0x03002C00
_080A2038: .4byte 0x000001F5
_080A203C: .4byte 0x0000FFFF
_080A2040:
	adds r0, r4, #0
	bl FUN_080a1f5c
	adds r6, r0, #0
	cmp r6, #0
	bne _080A206C
	movs r1, #0x99
	lsls r1, r1, #2
	adds r0, r4, r1
	ldr r0, [r0]
	cmp r0, #0
	beq _080A205E
	movs r1, #0
	bl VM_ExecByID
_080A205E:
	movs r0, #0
	bl FUN_0808670c
	strh r6, [r5]
	ldr r0, _080A2098 @ =0x00000199
	bl PlaySound_082406e0
_080A206C:
	adds r1, r4, #0
	adds r1, #0xbe
	ldrh r0, [r1]
	adds r0, #1
	strh r0, [r1]
	ldr r2, _080A209C @ =0x0000FFFF
	adds r1, r2, #0
	ands r0, r1
	movs r1, #3
	ands r0, r1
	cmp r0, #0
	bne _080A2090
	adds r0, r4, #0
	adds r0, #0xb8
	ldr r1, [r0]
	adds r0, r4, #0
	bl FUN_080a1e78
_080A2090:
	pop {r4, r5, r6}
	pop {r0}
	bx r0
	.align 2, 0
_080A2098: .4byte 0x00000199
_080A209C: .4byte 0x0000FFFF

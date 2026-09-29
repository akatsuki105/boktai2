	push {r4, r5, r6, r7, lr}
	mov r7, r8
	push {r7}
	adds r6, r0, #0
	movs r0, #0x48
	adds r0, r0, r6
	mov r8, r0
	adds r5, r6, #0
	adds r5, #0x60
	adds r4, r1, #0
	movs r7, #0
	b _080114F2
_080114C4:
	cmp r1, #0xf0
	bne _080114E2
	ldr r0, [r6, #0x78]
	bl VM_ParseStringRef
	bl Textbox_LookupString
	adds r1, r0, #0
	adds r1, #0xa0
	ldrb r1, [r1]
	strb r1, [r4]
	adds r0, #0xa1
	ldrb r0, [r0]
	strb r0, [r4, #1]
	b _080114E8
_080114E2:
	movs r0, #0x80
	strb r0, [r4]
	strb r1, [r4, #1]
_080114E8:
	adds r7, #1
	adds r4, #2
	adds r5, #2
	cmp r7, #4
	bgt _080114F8
_080114F2:
	ldrh r1, [r5]
	cmp r1, #0
	bne _080114C4
_080114F8:
	movs r0, #0
	strb r0, [r4]
	ldr r1, _0801151C @ =0x030046A0
	ldr r2, [r1]
	mov r3, r8
	ldrh r0, [r3, #2]
	strh r0, [r2, #0xa]
	ldr r2, [r1]
	ldrh r0, [r3, #0x14]
	strh r0, [r2, #0xc]
	ldr r1, [r1]
	ldrh r0, [r3, #0x16]
	strh r0, [r1, #0xe]
	pop {r3}
	mov r8, r3
	pop {r4, r5, r6, r7}
	pop {r0}
	bx r0
	.align 2, 0
_0801151C: .4byte 0x030046A0

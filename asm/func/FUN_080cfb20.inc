	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0x2c
	ldrsh r0, [r5, r1]
	movs r2, #0xf2
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	bl Div
	strh r0, [r4]
	movs r1, #0x2e
	ldrsh r0, [r5, r1]
	ldr r2, _080CFBA8 @ =0x000003CA
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	ldr r1, _080CFBAC @ =0x000003C2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r1, #0x96
	adds r0, r0, r1
	movs r1, #5
	bl Div
	strh r0, [r4]
	movs r1, #0x30
	ldrsh r0, [r5, r1]
	movs r2, #0xf3
	lsls r2, r2, #2
	adds r1, r5, r2
	movs r2, #0
	ldrsh r1, [r1, r2]
	adds r0, r0, r1
	movs r1, #0xf1
	lsls r1, r1, #2
	adds r4, r5, r1
	movs r2, #0
	ldrsh r1, [r4, r2]
	lsls r1, r1, #2
	adds r0, r0, r1
	movs r1, #5
	bl Div
	strh r0, [r4]
	adds r0, r5, #0
	adds r0, #0x28
	ldrb r1, [r0]
	ldr r0, _080CFBB0 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080CFBB4
	movs r0, #1
	rsbs r0, r0, #0
	b _080CFBB8
	.align 2, 0
_080CFBA8: .4byte 0x000003CA
_080CFBAC: .4byte 0x000003C2
_080CFBB0: .4byte 0x03002C68
_080CFBB4:
	movs r2, #0x18
	ldrsh r0, [r0, r2]
_080CFBB8:
	cmp r1, r0
	bne _080CFBC6
	movs r1, #0xf0
	lsls r1, r1, #2
	adds r0, r5, r1
	bl Camera_LookAt
_080CFBC6:
	pop {r4, r5}
	pop {r0}
	bx r0

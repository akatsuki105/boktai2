	push {r4, r5, lr}
	adds r4, r0, #0
	adds r5, r1, #0
	ldr r1, _08103288 @ =0x000001DF
	adds r0, r4, r1
	ldrb r0, [r0]
	cmp r0, #8
	bne _08103298
	adds r0, r4, #0
	bl Enemy_IsDead
	lsls r0, r0, #0x18
	cmp r0, #0
	bne _08103298
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	ldr r1, [r0]
	ldr r2, _0810328C @ =0x00000714
	adds r0, r1, r2
	ldrh r0, [r0]
	cmp r0, #0
	bne _08103298
	subs r2, #6
	adds r0, r1, r2
	ldrb r0, [r0]
	cmp r0, #0
	bne _08103298
	ldr r0, _08103290 @ =0x0000070D
	adds r2, r1, r0
	ldrb r3, [r2]
	ldrh r1, [r5, #2]
	adds r0, r3, r1
	cmp r0, #6
	ble _08103294
	movs r0, #6
	b _08103296
	.align 2, 0
_08103288: .4byte 0x000001DF
_0810328C: .4byte 0x00000714
_08103290: .4byte 0x0000070D
_08103294:
	adds r0, r3, r1
_08103296:
	strb r0, [r2]
_08103298:
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0

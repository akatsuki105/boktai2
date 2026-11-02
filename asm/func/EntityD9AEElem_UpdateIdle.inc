	push {r4, lr}
	adds r2, r0, #0
	ldrb r3, [r2]
	cmp r3, #1
	bne _08003F64
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08003F7A
	ldr r1, _08003F60 @ =EntityD9AEElem_UpdateBreak
	movs r4, #0xcc
	lsls r4, r4, #1
	adds r0, r2, r4
	str r1, [r0]
	movs r0, #0
	strh r0, [r2, #2]
	strb r3, [r2, #0x11]
	movs r0, #3
	strh r0, [r2, #4]
	b _08003F7A
	.align 2, 0
_08003F60: .4byte EntityD9AEElem_UpdateBreak
_08003F64:
	movs r1, #0x16
	ldrsh r0, [r2, r1]
	cmp r0, #0
	bgt _08003F7A
	movs r0, #0
	movs r1, #3
	strb r1, [r2, #0x19]
	movs r3, #0xcc
	lsls r3, r3, #1
	adds r1, r2, r3
	str r0, [r1]
_08003F7A:
	pop {r4}
	pop {r0}
	bx r0

	push {r4, lr}
	adds r4, r0, #0
	bl FUN_080cc370
	ldr r0, [r4, #0x1c]
	cmp r0, #1
	bne _080D811E
	adds r0, r4, #0
	bl FUN_080d78dc
	cmp r0, #0
	beq _080D8118
	adds r0, r4, #0
	bl FUN_080d040c
	b _080D811E
_080D8118:
	adds r0, r4, #0
	bl FUN_080d7b50
_080D811E:
	adds r0, r4, #0
	bl FUN_080d7fbc
	movs r1, #0xac
	lsls r1, r1, #4
	adds r0, r4, r1
	ldr r1, [r0]
	adds r0, r4, #0
	bl _call_via_r1
	adds r0, r4, #0
	bl FUN_080ce28c
	ldr r1, _080D8154 @ =0x03002BC0
	ldr r0, [r4, #0x18]
	lsls r0, r0, #2
	adds r0, r0, r1
	ldr r1, [r4, #0x1c]
	str r1, [r0]
	ldr r0, _080D8158 @ =0x03002C68
	ldr r0, [r0]
	cmp r0, #0
	bne _080D815C
	movs r1, #1
	rsbs r1, r1, #0
	b _080D8160
	.align 2, 0
_080D8154: .4byte 0x03002BC0
_080D8158: .4byte 0x03002C68
_080D815C:
	movs r2, #0x18
	ldrsh r1, [r0, r2]
_080D8160:
	ldr r0, [r4, #0x18]
	cmp r0, r1
	bne _080D8192
	ldr r1, _080D81C4 @ =0x030046A0
	ldr r2, [r1]
	ldrh r0, [r4, #0x2c]
	strh r0, [r2, #0x30]
	ldr r2, [r1]
	ldrh r0, [r4, #0x2e]
	strh r0, [r2, #0x32]
	ldr r2, [r1]
	ldrh r0, [r4, #0x30]
	strh r0, [r2, #0x34]
	ldr r2, [r1]
	ldr r0, _080D81C8 @ =0x00000932
	adds r2, r2, r0
	movs r1, #0xba
	lsls r1, r1, #2
	adds r0, r4, r1
	ldrb r0, [r0]
	adds r0, #5
	movs r1, #7
	ands r0, r1
	lsls r0, r0, #5
	strh r0, [r2]
_080D8192:
	ldr r2, _080D81CC @ =0x0000045A
	adds r0, r4, r2
	movs r1, #0
	strh r1, [r0]
	adds r2, #2
	adds r0, r4, r2
	str r1, [r0]
	ldr r0, [r4, #0x1c]
	cmp r0, #8
	beq _080D81BC
	movs r1, #0xe8
	lsls r1, r1, #1
	adds r0, r4, r1
	adds r1, r4, #0
	adds r1, #0x2c
	str r1, [r0]
	movs r2, #0xe6
	lsls r2, r2, #1
	adds r0, r4, r2
	bl FUN_08234660
_080D81BC:
	movs r0, #0
	pop {r4}
	pop {r1}
	bx r1
	.align 2, 0
_080D81C4: .4byte 0x030046A0
_080D81C8: .4byte 0x00000932
_080D81CC: .4byte 0x0000045A

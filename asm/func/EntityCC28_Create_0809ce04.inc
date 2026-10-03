	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809CE44 @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	bne _0809CE5A
	ldr r1, _0809CE48 @ =0x0000405C
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809CE58
	ldr r1, _0809CE4C @ =FUN_0809cbd0
	ldr r2, _0809CE50 @ =FUN_0809cc04
	bl SetEntityRoutine
	ldr r1, _0809CE54 @ =0x000009FA
	adds r0, r4, r1
	strh r5, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0809cc48
	cmp r0, #0
	bge _0809CE58
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809CE5A
	.align 2, 0
_0809CE44: .4byte 0x0300013C
_0809CE48: .4byte 0x0000405C
_0809CE4C: .4byte FUN_0809cbd0
_0809CE50: .4byte FUN_0809cc04
_0809CE54: .4byte 0x000009FA
_0809CE58:
	adds r0, r4, #0
_0809CE5A:
	pop {r4, r5}
	pop {r1}
	bx r1

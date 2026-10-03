	push {r4, r5, lr}
	adds r5, r0, #0
	ldr r0, _0809CBB4 @ =0x0300013C
	ldr r0, [r0]
	cmp r0, #0
	bne _0809CBCA
	ldr r1, _0809CBB8 @ =0x0000405C
	movs r0, #0xc
	bl CreateEntity
	adds r4, r0, #0
	cmp r4, #0
	beq _0809CBC8
	ldr r1, _0809CBBC @ =FUN_0809c8e8
	ldr r2, _0809CBC0 @ =FUN_0809c928
	bl SetEntityRoutine
	ldr r1, _0809CBC4 @ =0x000009FA
	adds r0, r4, r1
	strh r5, [r0]
	adds r0, r4, #0
	adds r1, r5, #0
	bl FUN_0809cae0
	cmp r0, #0
	bge _0809CBC8
	adds r0, r4, #0
	bl KillEntity
	movs r0, #0
	b _0809CBCA
	.align 2, 0
_0809CBB4: .4byte 0x0300013C
_0809CBB8: .4byte 0x0000405C
_0809CBBC: .4byte FUN_0809c8e8
_0809CBC0: .4byte FUN_0809c928
_0809CBC4: .4byte 0x000009FA
_0809CBC8:
	adds r0, r4, #0
_0809CBCA:
	pop {r4, r5}
	pop {r1}
	bx r1

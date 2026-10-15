	push {r4, r5, lr}
	adds r5, r0, #0
	movs r1, #0xa4
	lsls r1, r1, #1
	adds r0, r5, r1
	ldr r1, _081E367C @ =0x00000AA8
	adds r4, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	adds r0, r5, #0
	adds r0, #0xe8
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	adds r0, r5, #0
	adds r0, #0x88
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	adds r0, r5, #0
	adds r0, #0x28
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xb2
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0x9a
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0x82
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xd4
	lsls r1, r1, #1
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xe2
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xca
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0x89
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xfa
	lsls r1, r1, #2
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xa1
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0x95
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xb9
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	movs r1, #0xad
	lsls r1, r1, #3
	adds r0, r5, r1
	adds r1, r4, #0
	movs r2, #0
	bl MainSprite_LoadPose
	pop {r4, r5}
	pop {r0}
	bx r0
	.align 2, 0
_081E367C: .4byte 0x00000AA8
